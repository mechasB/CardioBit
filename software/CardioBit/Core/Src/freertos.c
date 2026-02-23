/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticSemaphore_t osStaticMutexDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for CommTask */
osThreadId_t CommTaskHandle;
const osThreadAttr_t CommTask_attributes = {
  .name = "CommTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for MeasureTask */
osThreadId_t MeasureTaskHandle;
const osThreadAttr_t MeasureTask_attributes = {
  .name = "MeasureTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for CalculationTask */
osThreadId_t CalculationTaskHandle;
const osThreadAttr_t CalculationTask_attributes = {
  .name = "CalculationTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for dataMutex */
osMutexId_t dataMutexHandle;
osStaticMutexDef_t dataMutexControlBlock;
const osMutexAttr_t dataMutex_attributes = {
  .name = "dataMutex",
  .cb_mem = &dataMutexControlBlock,
  .cb_size = sizeof(dataMutexControlBlock),
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartCommunicationTask(void *argument);
void StartMeasureTask(void *argument);
void StartCalculationTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* creation of dataMutex */
  dataMutexHandle = osMutexNew(&dataMutex_attributes);

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of CommTask */
  CommTaskHandle = osThreadNew(StartCommunicationTask, NULL, &CommTask_attributes);

  /* creation of MeasureTask */
  MeasureTaskHandle = osThreadNew(StartMeasureTask, NULL, &MeasureTask_attributes);

  /* creation of CalculationTask */
  CalculationTaskHandle = osThreadNew(StartCalculationTask, NULL, &CalculationTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartCommunicationTask */
/**
  * @brief  Function implementing the CommTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartCommunicationTask */
void StartCommunicationTask(void *argument)
{
  /* USER CODE BEGIN StartCommunicationTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCommunicationTask */
}

/* USER CODE BEGIN Header_StartMeasureTask */
/**
* @brief Function implementing the MeasureTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartMeasureTask */
void StartMeasureTask(void *argument)
{
  /* USER CODE BEGIN StartMeasureTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartMeasureTask */
}

/* USER CODE BEGIN Header_StartCalculationTask */
/**
* @brief Function implementing the CalculationTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCalculationTask */
void StartCalculationTask(void *argument)
{
  /* USER CODE BEGIN StartCalculationTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCalculationTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

