
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"



#ifndef __usdelay_h
#define __usdelay_h

/* Delay 5 microseconds in blocking mode */
void USDELAY_5us(void);

/* Delay 10 microseconds in blocking mode */
void USDELAY_10us(void);

/* Delay 50 microseconds in blocking mode */
void USDELAY_50us(void);

/* Delay from 100 to 1000 microseconds in non-blocking mode
 *
 * @brief	A hardware timer with period elapsed interrupt used
 *
 * @param	Delay in microseconds. Allowed values from 100us to 1000us
 *
 * @param	Semaphore handle
 *
 * @param	TIM handle
 *
 * @note	Use TIM2 to TIM5 general purpose timers
 * 			Set the prescaler value equal to timer's input clock in MHz
 * 			in order to make 1 tick = 1 us
 *
 * 			Example: If input clock 36Mhz, set PSC = 36
 */
void USDELAY_100_1000us(uint16_t delayUs, osSemaphoreId *SemHandle, TIM_HandleTypeDef *htim);

/* Timer period elapsed interrupt service routine */
void USDELAY_TIMPeriodElapsedISR(osSemaphoreId *SemHandle, TIM_HandleTypeDef *htim);

#endif /* __usdelay_h */

/* end of usdelay.h */
