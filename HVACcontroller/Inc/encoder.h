
#include "stm32f1xx_hal.h"



#ifndef __encoder_h
#define __encoder_h

/* Minimum push signal duration for assigning a push command */
#define ENCODER_PUSH_DURATION		(25)

/* Encoder status */
typedef enum
{
	ENCODER_CHANGED,
	ENCODER_NOT_CHANGED
} ENCODER_Status;

/* Command from encoder */
typedef enum
{
	ENCODER_CMD_PUSH,
	ENCODER_CMD_CW,
	ENCODER_CMD_CCW
} ENCODER_Command;

/* Encoder push button state */
typedef enum
{
	ENCODER_PUSH_LOW = 0U,
	ENCODER_PUSH_HIGH
} ENCODER_PushState;

/* Encoder A and B signal state */
typedef enum
{
	ENCODER_AB_00,
	ENCODER_AB_01,
	ENCODER_AB_11,
	ENCODER_AB_10
} ENCODER_ABState;

/* Encoder overall state */
typedef struct
{
	ENCODER_PushState Push;
	ENCODER_ABState AB;
} ENCODER_State;

/* Scan encoder inputs and get encoder state */
ENCODER_State ENCODER_GetState(void);

/* Handle encoder state and assign the command */
ENCODER_Status ENCODER_GetCommand(ENCODER_Command *Command, ENCODER_State *PreviousState, ENCODER_State *CurrentState, uint16_t *pushCnt);

#endif /* __encoder_h */

/* end of encoder.h */
