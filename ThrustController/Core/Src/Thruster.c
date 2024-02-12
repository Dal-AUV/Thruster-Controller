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



        // This function is used to forcibly set a new Pulse value for this Timer and Channel
       		  //pulse_width cannot exceed 255 (as that is the total period)
       		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse_width);

       		  // Increasing pulse width
       		  pulse_width=pulse_width+10;
       		  if (pulse_width>200) pulse_width=0;
    }
}

