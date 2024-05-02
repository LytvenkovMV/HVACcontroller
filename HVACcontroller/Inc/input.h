
#include "stm32f1xx_hal.h"
#include "usdelay.h"
#include "bus.h"
#include "command.h"



#ifndef __input_h
#define __input_h

typedef enum
{
	INPUT_RESET,
	INPUT_SET
} INPUT_State;

typedef struct
{
	INPUT_State Input01;
	INPUT_State Input02;
	INPUT_State Input03;
	INPUT_State Input04;
	INPUT_State Input05;
	INPUT_State Input06;
	INPUT_State Input07;
	INPUT_State Input08;
	INPUT_State Input09;
	INPUT_State Input10;
	INPUT_State Input11;
} INPUT_States;

/* External interrupt option */
typedef enum
{
	INPUT_WITH_FALLING_EDGE,
	INPUT_WITH_RISING_EDGE
} INPUT_ExIToption;

/* Get input states */
void INPUT_GetStates(INPUT_States *States);

/* Get input state by the input number */
INPUT_State INPUT_GetStateByNumber(INPUT_States *States, uint8_t number);

/* Get commands from the inputs */
void INPUT_GetCommands(COMMAND_Commands *Commands, INPUT_States PreviousStates, INPUT_States CurrentStates);

/* Get protection input state */
INPUT_State INPUT_GetProtectionState();

/* Configure external interrupt */
void INPUT_ConfigureExternalInterrupt(INPUT_ExIToption ExIToption);

#endif /* __input_h */

/* end of input.h */
