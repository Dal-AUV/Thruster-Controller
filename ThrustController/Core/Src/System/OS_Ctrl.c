/**
 * @file OS_Ctrl.c
 * @author Matthew Cockburn 
 * @brief OS Ctrl Contains the allocation of the RTOS resources
 * including Task definitions, mutexs, queues, timers, etc
 * @version 1.0
 * @date 2023-10-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Headers */
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "build.h"
#include "System/OS_Ctrl.h"
#include "Interfaces/ros_if.h"
#include "Peripherals/usart.h"
#include "Thruster.h"


/* Global Variables */
// Queues
QueueHandle_t DEBUG_ReaderQueue;
// Semaphores
SemaphoreHandle_t DEBUG_WriterSem;

/* Private Prototypes */
static void OS_HeartbeatTask(void);

/* Public Functions */
void OS_TasksInit(void){
        /* Added task to Kernel List */
    if(pdPASS != xTaskCreate((TaskFunction_t)OS_HeartbeatTask,"OS Heartbeat",
            configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY,NULL)){
        return;
    }
    if(pdPASS != xTaskCreate((TaskFunction_t)THRUSTER_Task,"Thruster",
            configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, NULL)){
        return;
    }
    return;
}

void OS_QueuesInit(void){
    DEBUG_ReaderQueue = xQueueCreate(MAX_USART_QUEUE_SIZE, sizeof(uint8_t));
    
    return;
}

void OS_SemaphoreInit(void){
    DEBUG_WriterSem = xSemaphoreCreateBinary();
    xSemaphoreGive(DEBUG_WriterSem);

    return;
}

void OS_MutexesInit(void){
    return;
}
/* End of Public Functions */

/* Private Functions */
/**
 * @brief The OS Heartbeat Task, blinks the Green LED
 * on the Dev board. Used as a visual status queue
 */
static void OS_HeartbeatTask(void){
	while (1)
    {
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		DEBUG_Write("HeartBeat\n\r");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    return;
}
/* End of Private Functions */
