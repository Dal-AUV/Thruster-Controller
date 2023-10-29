/**
 * @file usart.h
 * @author Matthew Cockburn
 * @brief Header file for the USART hardware interfaces
 * @version 1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef INC_PERIPHERALS_USART_H_
#define INC_PERIPHERALS_USART_H_

/* Headers */
#include <stdbool.h>
#include "main.h"

#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
/* Definitions */
#define MAX_USART_BUF_SIZE 50
#define MAX_USART_QUEUE_SIZE 80
#define UART_RX_ISR_TRIGGER_SZ 1

typedef enum UART_SENSORS_e{
    UART_ROS,
    UART_DEBUG,
    UART_SENSORS_TOTAL
}UART_SENSORS_t;

/* Public Functions */
/**
 * @brief Initializes all defined UART interfaces
 * @return HAL_StatusTypeDef 
 */
void UART_Init(void);

/**
 * @brief 
 * Write a debugging message to an external interface 
 * @param format string 
 * @param ... variables
 * @return HAL_StatusTypeDef 
 */
HAL_StatusTypeDef DEBUG_Write(const char *format, ...);

#endif /* INC_PERIPHERALS_USART_H_ */
