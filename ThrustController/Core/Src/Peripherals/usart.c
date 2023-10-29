/**
 * @file usart.c
 * @author Matthew Cockburn & Wyatt Shaw
 * @brief Source file for the USART hardware interfaces, contains ISR 
 * implementation, Receive and Transmit functions
 * @version 1
 * @date 2023-10-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Standard Headers */
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
/* Middleware Headers */
#include "main.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
/* Application Headers */
#include "Peripherals/usart.h"
#include "System/OS_Ctrl.h"

/* Definitions */
#define DEBUG_WRITE_TIMEOUT_MS 100
/* Public Variables */

// HAL UART Handles
UART_HandleTypeDef huart2;
// HAL DMA Handles
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;
// Receive Buffers
uint8_t DEBUG_Buf[MAX_USART_BUF_SIZE];
uint8_t ROS_Buf[MAX_USART_BUF_SIZE];
// Transmit Buffers
uint8_t DEBUG_TxBuf[MAX_USART_BUF_SIZE];

/* Private Prototypes */
static void MX_USART2_UART_Init(void);
HAL_StatusTypeDef UART_DMA_Write(UART_HandleTypeDef *huart, uint8_t *buf, uint16_t size);

/* Public Functions */
void UART_Init(void){
    MX_USART2_UART_Init();

    return;
}

HAL_StatusTypeDef DEBUG_Write(const char *format, ...){
  // Acquire the semaphore 
  if(pdFALSE == xSemaphoreTake(DEBUG_WriterSem, pdMS_TO_TICKS(portMAX_DELAY))){
    return HAL_TIMEOUT;
  }
  // Clear Write Buffer
  memset(DEBUG_TxBuf,0,sizeof(DEBUG_TxBuf));

  va_list args;
  va_start(args, format);
  vsnprintf((char*)DEBUG_TxBuf, sizeof(DEBUG_TxBuf), format, args);
  va_end(args);

  return UART_DMA_Write(&huart2, DEBUG_TxBuf,(uint16_t)strlen((char*)DEBUG_TxBuf));
}

/* UART Callbacks */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    if (huart == &huart2){
      xQueueSendToBackFromISR(DEBUG_ReaderQueue,DEBUG_Buf,NULL);
      HAL_UART_Receive_IT(&huart2, DEBUG_Buf, UART_RX_ISR_TRIGGER_SZ);
    }
    return;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if(huart == &huart2){
		xSemaphoreGiveFromISR(DEBUG_WriterSem,NULL);
	}
	return;
}

/* Private Implementations */
/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{
  
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }

}
/**
 * @brief Write a buffer using DMA
 * @param huart uart hardware handle
 * @param buf buffer to be written
 * @param size size of the buffer to be written
 * @return HAL_StatusTypeDef 
 */
HAL_StatusTypeDef UART_DMA_Write(UART_HandleTypeDef *huart, uint8_t *buf, uint16_t size)
{
    if(size == 0) return HAL_OK;
    
    return HAL_UART_Transmit_DMA(huart, buf, size);
}
