
#include "usdelay.h"



void USDELAY_5us(void)
{
	uint32_t cyclesNumber = 0;

	cyclesNumber = (HAL_RCC_GetHCLKFreq() / 1000000) >> 2;

	for (uint32_t tick = 0; tick < cyclesNumber; tick++)
	{
		__asm__ __volatile__ ( "nop" );
	}
}



void USDELAY_10us(void)
{
	uint32_t cyclesNumber = 0;

	cyclesNumber = (HAL_RCC_GetHCLKFreq() / 1000000);

	for (uint32_t tick = 0; tick < cyclesNumber; tick++)
	{
		__asm__ __volatile__ ( "nop" );
	}
}



void USDELAY_50us(void)
{
	uint32_t cyclesNumber = 0;

	cyclesNumber = 5 * (HAL_RCC_GetHCLKFreq() / 1000000);

	for (uint32_t tick = 0; tick < cyclesNumber; tick++)
	{
		__asm__ __volatile__ ( "nop" );
	}
}



void USDELAY_100_1000us(uint16_t delayUs, osSemaphoreId *SemHandle, TIM_HandleTypeDef *htim)
{
	/* Stop the timer */
	HAL_TIM_Base_Stop_IT(htim);

	/* Set minimum delay */
	if (delayUs < 100) delayUs = 100;

	/* Initialize CNT and ARR */
	htim->Instance->CNT = 0;
	htim->Instance->ARR = delayUs;

	/* Start the timer */
	HAL_TIM_Base_Start_IT(htim);

	/* Wait period elapsed semaphore */
	xSemaphoreTake(SemHandle, portMAX_DELAY);
}



void USDELAY_TIMPeriodElapsedISR(osSemaphoreId *SemHandle, TIM_HandleTypeDef *htim)
{
	/* Private variables */
	static portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

	/* Stop the timer */
	HAL_TIM_Base_Stop_IT(htim);

	/* Give I2C period elapsed semaphore */
	xSemaphoreGiveFromISR(SemHandle, &xHigherPriorityTaskWoken);

	/* Switch context if giving the semaphore caused a task to unblock, and the unblocked task has a priority higher than the currently running task */
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
