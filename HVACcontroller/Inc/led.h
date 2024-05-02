
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "bus.h"



#ifndef __led_h
#define __led_h

/* LED state */
typedef enum
{
  LED_OFF = 0U,
  LED_ON
} LED_State;


/* LED name */
typedef enum
{
	LED1 = 1,
	LED2 = 2,
	LED3 = 3,
	LED4 = 4,
	LED5 = 5
} LED_Name;


/* LEDs overall state */
typedef struct
{
	LED_State LED1State;
	LED_State LED2State;
	LED_State LED3State;
	LED_State LED4State;
	LED_State LED5State;
} LED_States;


/* LED command */
typedef struct
{
	LED_Name Name;
	LED_State NewState;
} LED_ChangeQuery;

/* Initialize LEDs */
void LED_Init(LED_States *States);

/* Send query to turn on/off LEDs */
void LED_SendQuery(LED_Name Name, LED_State NewState, osMessageQId *LedQueueHandle, uint16_t const waitingTimeMs);

/* Modify LED states according to the query and turn on/off LEDs */
void LED_HandleQuery(LED_ChangeQuery Query, LED_States *States);

#endif /* __led_h */

/* end of led.h */
