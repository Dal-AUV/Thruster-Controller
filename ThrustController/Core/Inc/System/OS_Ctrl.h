/**
 * @file OS_Ctrl.h
 * @author Matthew Cockburn
 * @brief OS Ctrl contains the allocation of the RTOS resources
 * including Tasks, mutexs, semaphores, queues, timers, etc
 * @version 1
 * @date 2023-10-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _INC_OS_CTRL_H_
#define _INC_OS_CTRL_H_
/* Headers */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
/* Macros */
// Task Config
#define OS_HEARTBEAT_PRI tskIDLE_PRIORITY

#define OS_HEARTBEAT_STACK_SIZE configMINIMAL_STACK_SIZE

// Queue Config

/* External Variables */
extern QueueHandle_t DEBUG_ReaderQueue;

extern SemaphoreHandle_t DEBUG_WriterSem;
extern SemaphoreHandle_t DEBUG_ReaderSem;

/* Public Function Prototypes */
/**
 * @brief Initialize all tasks run by the RTOS kernel
 */
void OS_TasksInit(void);
/**
 * @brief Initialize all Queues used in the firmware
 */
void OS_QueuesInit(void);
/**
 * @brief Initialize all Semaphores used in the firmware
 */
void OS_SemaphoreInit(void);
/**
 * @brief Initialize all Mutexes used in the firmware
 */
void OS_MutexesInit(void);

#endif /* _INC_OS_CTRL_H_ */