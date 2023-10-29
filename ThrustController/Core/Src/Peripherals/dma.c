/**
 * @file dma.c
 * @author Matthew Cockburn
 * @brief Source file for the dma interface
 * @version 1
 * @date 2023-10-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "main.h"
#include "Peripherals/dma.h"
#include "Peripherals/usart.h"

/**
  * Enable DMA controller clock
  */
void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);
  /* DMA1_Channel7_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel7_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel7_IRQn);

}
