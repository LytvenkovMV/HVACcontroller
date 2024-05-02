
#include "led.h"



void LED_Delay5nop(void)
{
	do
	{
		__asm__ __volatile__ ( "nop" );
		__asm__ __volatile__ ( "nop" );
		__asm__ __volatile__ ( "nop" );
		__asm__ __volatile__ ( "nop" );
		__asm__ __volatile__ ( "nop" );
	} while (0);
}



void LED_WriteToBus(LED_States *States)
{
	BUS_Data Data;

	/* Prepare data to write to the bus */
	if (States->LED1State == LED_ON) Data.D4LineState = BUS_LINE_SET; else Data.D4LineState = BUS_LINE_RESET;
	if (States->LED2State == LED_ON) Data.D3LineState = BUS_LINE_SET; else Data.D3LineState = BUS_LINE_RESET;
	if (States->LED3State == LED_ON) Data.D2LineState = BUS_LINE_SET; else Data.D2LineState = BUS_LINE_RESET;
	if (States->LED4State == LED_ON) Data.D1LineState = BUS_LINE_SET; else Data.D1LineState = BUS_LINE_RESET;
	if (States->LED5State == LED_ON) Data.D0LineState = BUS_LINE_SET; else Data.D0LineState = BUS_LINE_RESET;
	Data.D5LineState = BUS_LINE_RESET;
	Data.D6LineState = BUS_LINE_RESET;
	Data.D7LineState = BUS_LINE_RESET;

	/* Write data to the bus */
	BUS_Write(Data);
	LED_Delay5nop();

	/* Latch data in the output register */
	HAL_GPIO_WritePin(LE1_GPIO_Port, LE1_Pin, GPIO_PIN_SET);
	LED_Delay5nop();
	LED_Delay5nop();
	LED_Delay5nop();
	LED_Delay5nop();
	HAL_GPIO_WritePin(LE1_GPIO_Port, LE1_Pin, GPIO_PIN_RESET);
	LED_Delay5nop();
}



void LED_Init(LED_States *States)
{
	States->LED1State = LED_OFF;
	States->LED2State = LED_OFF;
	States->LED3State = LED_OFF;
	States->LED4State = LED_OFF;
	States->LED5State = LED_OFF;

	LED_WriteToBus(States);
}



void LED_SendQuery(LED_Name Name, LED_State NewState, osMessageQId *LedQueueHandle, uint16_t const waitingTimeMs)
{
	LED_ChangeQuery LedChangeQuery;

	LedChangeQuery.Name = Name;
	LedChangeQuery.NewState = NewState;
	xQueueSend(LedQueueHandle, &LedChangeQuery, waitingTimeMs);
}



void LED_HandleQuery(LED_ChangeQuery Query, LED_States *States)
{
	/* Modify LED states */
	switch(Query.Name)
		{
			case LED1:
				States->LED1State = Query.NewState;
			break;
			
			case LED2:
				States->LED2State = Query.NewState;
			break;

			case LED3:
				States->LED3State = Query.NewState;
			break;

			case LED4:
				States->LED4State = Query.NewState;
			break;

			case LED5:
				States->LED5State = Query.NewState;
			break;			
		}
	
	/* Write LED states to the bus */
	LED_WriteToBus(States);
}

