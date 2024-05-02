
#include "output.h"



void OUTPUT_ChangeState(OUTPUT_ID ID, OUTPUT_State NewState)
{
	GPIO_PinState PinState;
	
	PinState = GPIO_PIN_RESET;
	if (NewState == OUTPUT_ON) PinState = GPIO_PIN_SET;
		
	switch (ID)
	{
		case OUTPUT_COOLANT_HEATER_1:		HAL_GPIO_WritePin(BO1_GPIO_Port, BO1_Pin, PinState); break;
		case OUTPUT_COOLANT_HEATER_2:		HAL_GPIO_WritePin(BO2_GPIO_Port, BO2_Pin, PinState); break;
		case OUTPUT_AIR_HEATER_1:			HAL_GPIO_WritePin(BO3_GPIO_Port, BO3_Pin, PinState); break;
		case OUTPUT_AIR_HEATER_2:			HAL_GPIO_WritePin(BO4_GPIO_Port, BO4_Pin, PinState); break;
		case OUTPUT_INTAKE_VENT:			HAL_GPIO_WritePin(BO5_GPIO_Port, BO5_Pin, PinState); break;
		case OUTPUT_EXHAUST_VENT:			HAL_GPIO_WritePin(BO6_GPIO_Port, BO6_Pin, PinState); break;
		case OUTPUT_COOLANT_PUMP:			HAL_GPIO_WritePin(BO7_GPIO_Port, BO7_Pin, PinState); break;
		default: PinState = GPIO_PIN_RESET;
	}	
}



OUTPUT_State OUTPUT_GetState(OUTPUT_ID ID)
{
	GPIO_PinState PinState;
	
	switch (ID)
	{
		case OUTPUT_COOLANT_HEATER_1:		PinState = HAL_GPIO_ReadPin(BO1_GPIO_Port, BO1_Pin); break;
		case OUTPUT_COOLANT_HEATER_2:		PinState = HAL_GPIO_ReadPin(BO2_GPIO_Port, BO2_Pin); break;
		case OUTPUT_AIR_HEATER_1:			PinState = HAL_GPIO_ReadPin(BO3_GPIO_Port, BO3_Pin); break;
		case OUTPUT_AIR_HEATER_2:			PinState = HAL_GPIO_ReadPin(BO4_GPIO_Port, BO4_Pin); break;
		case OUTPUT_INTAKE_VENT:			PinState = HAL_GPIO_ReadPin(BO5_GPIO_Port, BO5_Pin); break;
		case OUTPUT_EXHAUST_VENT:			PinState = HAL_GPIO_ReadPin(BO6_GPIO_Port, BO6_Pin); break;
		case OUTPUT_COOLANT_PUMP:			PinState = HAL_GPIO_ReadPin(BO7_GPIO_Port, BO7_Pin); break;		
		default: PinState = GPIO_PIN_RESET;
	}
	
	if (PinState == GPIO_PIN_SET) return OUTPUT_ON;
	
	return OUTPUT_OFF;
}



OUTPUT_State OUTPUT_GetStateByNumber(uint8_t number)
{
	GPIO_PinState PinState;
	
	switch (number)
	{
		case 1: PinState = HAL_GPIO_ReadPin(BO1_GPIO_Port, BO1_Pin); break;
		case 2: PinState = HAL_GPIO_ReadPin(BO2_GPIO_Port, BO2_Pin); break;
		case 3: PinState = HAL_GPIO_ReadPin(BO3_GPIO_Port, BO3_Pin); break;
		case 4: PinState = HAL_GPIO_ReadPin(BO4_GPIO_Port, BO4_Pin); break;
		case 5: PinState = HAL_GPIO_ReadPin(BO5_GPIO_Port, BO5_Pin); break;
		case 6: PinState = HAL_GPIO_ReadPin(BO6_GPIO_Port, BO6_Pin); break;
		case 7: PinState = HAL_GPIO_ReadPin(BO7_GPIO_Port, BO7_Pin); break;		
		default: PinState = GPIO_PIN_RESET;
	}
	
	if (PinState == GPIO_PIN_SET) return OUTPUT_ON;
	
	return OUTPUT_OFF;
}
