
#include "input.h"



void INPUT_GetStates(INPUT_States *States)
{
	GPIO_PinState PinState;
	BUS_Data CurrData;
	
	States->Input01	= INPUT_RESET;
	States->Input02	= INPUT_RESET;
	States->Input03	= INPUT_RESET;
	States->Input04	= INPUT_RESET;
	States->Input05	= INPUT_RESET;
	States->Input06	= INPUT_RESET;
	States->Input07	= INPUT_RESET;
	States->Input08	= INPUT_RESET;
	States->Input09	= INPUT_RESET;
	States->Input10	= INPUT_RESET;
	States->Input11	= INPUT_RESET;
	
	/* Enable output of the register 1 */
	HAL_GPIO_WritePin(OE1_GPIO_Port, OE1_Pin, GPIO_PIN_RESET);
	USDELAY_10us();

	/* Read data and fill in States variable */
	BUS_Read(&CurrData);
	if (CurrData.D7LineState == BUS_LINE_RESET) States->Input01	= INPUT_SET;
	if (CurrData.D6LineState == BUS_LINE_RESET) States->Input02	= INPUT_SET;
	if (CurrData.D5LineState == BUS_LINE_RESET) States->Input03	= INPUT_SET;
	if (CurrData.D4LineState == BUS_LINE_RESET) States->Input04	= INPUT_SET;
	if (CurrData.D3LineState == BUS_LINE_RESET) States->Input05	= INPUT_SET;
	if (CurrData.D2LineState == BUS_LINE_RESET) States->Input06	= INPUT_SET;
	
	/* Disable output of the register 1 */
	HAL_GPIO_WritePin(OE1_GPIO_Port, OE1_Pin, GPIO_PIN_SET);
	USDELAY_10us();

	/* Enable output of the register 2 */
	HAL_GPIO_WritePin(OE2_GPIO_Port, OE2_Pin, GPIO_PIN_RESET);
	USDELAY_10us();
	
	/* Read data and fill in States variable */
	BUS_Read(&CurrData);
	if (CurrData.D3LineState == BUS_LINE_RESET) States->Input07	= INPUT_SET;
	if (CurrData.D4LineState == BUS_LINE_RESET) States->Input08	= INPUT_SET;
	if (CurrData.D5LineState == BUS_LINE_RESET) States->Input09	= INPUT_SET;
	if (CurrData.D6LineState == BUS_LINE_RESET) States->Input10	= INPUT_SET;
	
	/* Disable output of the register 2 */
	HAL_GPIO_WritePin(OE2_GPIO_Port, OE2_Pin, GPIO_PIN_SET);

	/* Read pin and fill in state of Input 11 */
	PinState = HAL_GPIO_ReadPin(BI11_GPIO_Port, BI11_Pin);
	if (PinState == GPIO_PIN_RESET) States->Input11 = INPUT_SET;
}



INPUT_State INPUT_GetStateByNumber(INPUT_States *States, uint8_t number)
{
	switch (number)
	{
		case 1:  return States->Input01;
		case 2:  return States->Input02;
		case 3:  return States->Input03;
		case 4:  return States->Input04;
		case 5:  return States->Input05;
		case 6:  return States->Input06;
		case 7:  return States->Input07;
		case 8:  return States->Input08;
		case 9:  return States->Input09;
		case 10: return States->Input10;
		case 11: return States->Input11;
		default: return INPUT_RESET;
	}
}



void INPUT_GetCommands(COMMAND_Commands *Commands, INPUT_States PreviousStates, INPUT_States CurrentStates)
{
	/* Reset commands status */
	Commands->ExVentStatus = COMMAND_NOT_CHANGED;
	Commands->IntVentStatus = COMMAND_NOT_CHANGED;
	Commands->HeatingStatus = COMMAND_NOT_CHANGED;
	
	/* Assign command by the falling edge of the signal from button */
	/* Assign exhaust ventilation command */
	if ((PreviousStates.Input09 == INPUT_SET) && (CurrentStates.Input09 == INPUT_RESET))
	{
		Commands->ExVentCommand = COMMAND_EX_VENT_TURN_OFF;
		Commands->ExVentStatus = COMMAND_CHANGED;
	}
	else if ((PreviousStates.Input10 == INPUT_SET) && (CurrentStates.Input10 == INPUT_RESET))
	{
		Commands->ExVentCommand = COMMAND_EX_VENT_TURN_ON;
		Commands->ExVentStatus = COMMAND_CHANGED;
	}
	
	/* Assign intake ventilation command */
	if ((PreviousStates.Input06 == INPUT_SET) && (CurrentStates.Input06 == INPUT_RESET))
	{
		Commands->IntVentCommand = COMMAND_INT_VENT_TURN_OFF;
		Commands->IntVentStatus = COMMAND_CHANGED;
	}
	else if ((PreviousStates.Input07 == INPUT_SET) && (CurrentStates.Input07 == INPUT_RESET))
	{
		Commands->IntVentCommand = COMMAND_INT_VENT_TURN_ON_WO_HEAT;
		Commands->IntVentStatus = COMMAND_CHANGED;
	}
	else if ((PreviousStates.Input08 == INPUT_SET) && (CurrentStates.Input08 == INPUT_RESET))
	{
		Commands->IntVentCommand = COMMAND_INT_VENT_TURN_ON_W_HEAT;
		Commands->IntVentStatus = COMMAND_CHANGED;
	}
	
	/* Assign heating command */
	if ((PreviousStates.Input01 == INPUT_SET) && (CurrentStates.Input01 == INPUT_RESET))
	{
		Commands->HeatingCommand = COMMAND_HEATING_TURN_OFF;
		Commands->HeatingStatus = COMMAND_CHANGED;
	}
	else if ((PreviousStates.Input02 == INPUT_SET) && (CurrentStates.Input02 == INPUT_RESET))
	{
		Commands->HeatingCommand = COMMAND_HEATING_TURN_ON_COMF;
		Commands->HeatingStatus = COMMAND_CHANGED;
	}
	else if ((PreviousStates.Input03 == INPUT_SET) && (CurrentStates.Input03 == INPUT_RESET))
	{
		Commands->HeatingCommand = COMMAND_HEATING_TURN_ON_ECO;
		Commands->HeatingStatus = COMMAND_CHANGED;
	}
	else if ((PreviousStates.Input04 == INPUT_SET) && (CurrentStates.Input04 == INPUT_RESET))
	{
		Commands->HeatingCommand = COMMAND_HEATING_TURN_ON_FRZ;
		Commands->HeatingStatus = COMMAND_CHANGED;
	}
	else if ((PreviousStates.Input05 == INPUT_SET) && (CurrentStates.Input05 == INPUT_RESET))
	{
		Commands->HeatingCommand = COMMAND_HEATING_TURN_ON_PROG;
		Commands->HeatingStatus = COMMAND_CHANGED;
	}
}



INPUT_State INPUT_GetProtectionState()
{
	GPIO_PinState PinState;

	PinState = HAL_GPIO_ReadPin(BI11_GPIO_Port, BI11_Pin);
	if (PinState == GPIO_PIN_RESET) return INPUT_SET;

	return INPUT_RESET;
}



void INPUT_ConfigureExternalInterrupt(INPUT_ExIToption ExIToption)
{
    uint8_t bitState = 0;

	switch (ExIToption)
	{
    case INPUT_WITH_RISING_EDGE:

    	/* Disable falling trigger */
    	bitState = READ_BIT(EXTI->FTSR, BI11_Pin);
    	if (bitState != 0) CLEAR_BIT(EXTI->FTSR, BI11_Pin);

    	/* Enable rising trigger */
    	bitState = READ_BIT(EXTI->RTSR, BI11_Pin);
    	if (bitState == 0) SET_BIT(EXTI->RTSR, BI11_Pin);

    	break;

    default:

    	/* Disable rising trigger */
    	bitState = READ_BIT(EXTI->RTSR, BI11_Pin);
    	if (bitState != 0) CLEAR_BIT(EXTI->RTSR, BI11_Pin);

    	/* Enable falling trigger */
    	bitState = READ_BIT(EXTI->FTSR, BI11_Pin);
    	if (bitState == 0) SET_BIT(EXTI->FTSR, BI11_Pin);
	}
}
