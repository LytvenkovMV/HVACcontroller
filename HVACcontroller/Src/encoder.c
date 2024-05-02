
#include "encoder.h"



ENCODER_State ENCODER_GetState(void)
{
	GPIO_PinState Pin1State, Pin2State, Pin3State;
	
	ENCODER_State State;

	/* Read encoder pins */
	Pin1State = HAL_GPIO_ReadPin(PUSH_GPIO_Port, PUSH_Pin);
	Pin2State = HAL_GPIO_ReadPin(A_GPIO_Port, A_Pin);
	Pin3State = HAL_GPIO_ReadPin(B_GPIO_Port, B_Pin);	
	
	/* Assign push button state */
	if (Pin1State == GPIO_PIN_RESET) State.Push = ENCODER_PUSH_HIGH; else State.Push = ENCODER_PUSH_LOW;
	
	/* Assign A and B signal state */	
	if      ((Pin2State == GPIO_PIN_SET)   && (Pin3State == GPIO_PIN_SET))   State.AB = ENCODER_AB_00;
	else if ((Pin2State == GPIO_PIN_SET)   && (Pin3State == GPIO_PIN_RESET)) State.AB = ENCODER_AB_01;
	else if ((Pin2State == GPIO_PIN_RESET) && (Pin3State == GPIO_PIN_SET))   State.AB = ENCODER_AB_10;
	else if ((Pin2State == GPIO_PIN_RESET) && (Pin3State == GPIO_PIN_RESET)) State.AB = ENCODER_AB_11;
	
	return State;
}



ENCODER_Status ENCODER_GetCommand(ENCODER_Command *Command, ENCODER_State *PreviousState, ENCODER_State *CurrentState, uint16_t *pushCnt)
{
	/* Analyze push signal and assign command */
	switch (CurrentState->Push)
	{
	case ENCODER_PUSH_LOW:
		/* If push time has elapsed */
		if (*pushCnt >= ENCODER_PUSH_DURATION)
		{
			/* Reset push counter */
			*pushCnt = 0;

			/* If encoder was pushed and then released return "push" command*/
			if (PreviousState->Push == ENCODER_PUSH_HIGH)
			{
				*Command = ENCODER_CMD_PUSH;
				return ENCODER_CHANGED;
			}
		}

		/* Reset push counter */
		*pushCnt = 0;
		break;

	case ENCODER_PUSH_HIGH:
		/* Increment push counter */
		if (*pushCnt < ENCODER_PUSH_DURATION) (*pushCnt) ++;
		break;

	default:;
	}

	/* Analyze A and B signals and assign command */
	if ((PreviousState->AB) == ENCODER_AB_00)
	{
		switch (CurrentState->AB)
		{
		case ENCODER_AB_10:
		{
			*Command = ENCODER_CMD_CCW;
			return ENCODER_CHANGED;
		}
		break;

		case ENCODER_AB_01:
		{
			*Command = ENCODER_CMD_CW;
			return ENCODER_CHANGED;
		}
		break;

		default:;
		}
	}

	return ENCODER_NOT_CHANGED;
}
