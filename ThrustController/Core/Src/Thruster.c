/**
 * @file Thruster.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Headers */
#include "FreeRTOS.h"
#include "task.h"
#include "Thruster.h"
#include "Peripherals/usart.h"

/* Macros */
#define THRUSTER_TASK_DELAY_MS 100

/* RTOS Task */
void THRUSTER_Task(void){
    uint8_t num = 0;
    while(1){
        num = rand();
        DEBUG_Write("Thruster Task: %02X\n\r",num);
        vTaskDelay(pdMS_TO_TICKS(THRUSTER_TASK_DELAY_MS));
    }
}

