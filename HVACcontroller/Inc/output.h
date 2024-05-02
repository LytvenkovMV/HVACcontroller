
#include "stm32f1xx_hal.h"



#ifndef __output_h
#define __output_h

typedef enum
{
	OUTPUT_OFF,
	OUTPUT_ON
} OUTPUT_State;

typedef enum
{
	OUTPUT_EXHAUST_VENT,
	OUTPUT_INTAKE_VENT,
	OUTPUT_AIR_HEATER_1,
	OUTPUT_AIR_HEATER_2,
	OUTPUT_COOLANT_HEATER_1,
	OUTPUT_COOLANT_HEATER_2,
	OUTPUT_COOLANT_PUMP
} OUTPUT_ID;

void OUTPUT_ChangeState(OUTPUT_ID ID, OUTPUT_State NewState);

OUTPUT_State OUTPUT_GetState(OUTPUT_ID ID);

OUTPUT_State OUTPUT_GetStateByNumber(uint8_t number);

#endif /* __output_h */

/* end of output.h */
