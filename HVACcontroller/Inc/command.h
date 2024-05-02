


#ifndef __command_h
#define __command_h

typedef enum
{
	COMMAND_NOT_CHANGED,
	COMMAND_CHANGED
} COMMAND_Status;

typedef enum
{
	COMMAND_EX_VENT_TURN_OFF,
	COMMAND_EX_VENT_TURN_ON
} COMMAND_ExVentCommand;

typedef enum
{
	COMMAND_INT_VENT_TURN_OFF,
	COMMAND_INT_VENT_TURN_ON_WO_HEAT,
	COMMAND_INT_VENT_TURN_ON_W_HEAT
} COMMAND_IntVentCommand;

typedef enum
{
	COMMAND_HEATING_TURN_OFF,
	COMMAND_HEATING_TURN_ON_COMF,
	COMMAND_HEATING_TURN_ON_ECO,
	COMMAND_HEATING_TURN_ON_FRZ,
	COMMAND_HEATING_TURN_ON_PROG
} COMMAND_HeatingCommand;

typedef struct
{
	COMMAND_Status ExVentStatus;
	COMMAND_Status IntVentStatus;
	COMMAND_Status HeatingStatus;
	COMMAND_ExVentCommand ExVentCommand;
	COMMAND_IntVentCommand IntVentCommand;
	COMMAND_HeatingCommand HeatingCommand;
} COMMAND_Commands;

#endif /* __command_h */

/* end of command.h */
