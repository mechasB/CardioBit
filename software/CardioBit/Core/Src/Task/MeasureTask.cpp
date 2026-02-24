#include "Task/MeasureTask.hpp"
#include "adc.h"
#include "stm32h7xx_hal_adc.h"
#include "tim.h"

extern osThreadId_t MeasureTaskHandle;

void StartMeasureTask(void *argument)
{
  /* USER CODE BEGIN StartMeasureTask */
  HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)CardioBit::Data::adcRawBuffer, CardioBit::BUFFER_SIZE);
  HAL_TIM_Base_Start(&htim3);
  /* Infinite loop */
  for(;;)
  {
    osThreadFlagsWait(0x01, osFlagsWaitAny, osWaitForever);

    SCB_InvalidateDCache_by_Addr((uint32_t*)CardioBit::Data::adcRawBuffer, sizeof(CardioBit::Data::adcRawBuffer));

    for(uint32_t i = 0; i < CardioBit::BUFFER_SIZE; i++) {
            CardioBit::Data::ecgFloatBuffer[i] = static_cast<float32_t>(CardioBit::Data::adcRawBuffer[i]);
    }

    osDelay(1);
  }
  /* USER CODE END StartMeasureTask */
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if(hadc->Instance == ADC1)
    {
        osThreadFlagsSet(MeasureTaskHandle, 0x01);
    }
}