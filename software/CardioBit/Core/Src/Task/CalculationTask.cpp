#include "Task/CalculationTask.hpp"

extern osThreadId_t CalculationTaskHandle;

void StartCalculationTask(void *argument)
{
  /* USER CODE BEGIN StartCalculationTask */
  CardioBit::LowPassFilter ecgFilter;
  /* Infinite loop */
  for(;;)
  {
    osThreadFlagsWait(0x02, osFlagsWaitAny, osWaitForever);

    ecgFilter.process(CardioBit::Data::ecgFloatBuffer, 
                      CardioBit::Data::ecgFloatBuffer, 
                      CardioBit::BUFFER_SIZE);

    osDelay(1);
  }
  /* USER CODE END StartCalculationTask */
}