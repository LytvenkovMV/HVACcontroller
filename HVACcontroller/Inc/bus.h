
#include "stm32f1xx_hal.h"



#ifndef __bus_h
#define __bus_h

/* Define control registers and control bits for the bus pins */
/* D0 pin */
#define BUS_D0_CRx							CRH
#define BUS_D0_GPIO_CRx_MODEx				GPIO_CRH_MODE8
#define BUS_D0_GPIO_CRx_CNFx				GPIO_CRH_CNF8
#define BUS_D0_GPIO_CRx_MODEx_Pos			GPIO_CRH_MODE8_Pos
#define BUS_D0_GPIO_CRx_CNFx_Pos			GPIO_CRH_CNF8_Pos
/* D1 pin */
#define BUS_D1_CRx							CRH
#define BUS_D1_GPIO_CRx_MODEx				GPIO_CRH_MODE9
#define BUS_D1_GPIO_CRx_CNFx				GPIO_CRH_CNF9
#define BUS_D1_GPIO_CRx_MODEx_Pos			GPIO_CRH_MODE9_Pos
#define BUS_D1_GPIO_CRx_CNFx_Pos			GPIO_CRH_CNF9_Pos
/* D2 pin */
#define BUS_D2_CRx							CRH
#define BUS_D2_GPIO_CRx_MODEx				GPIO_CRH_MODE8
#define BUS_D2_GPIO_CRx_CNFx				GPIO_CRH_CNF8
#define BUS_D2_GPIO_CRx_MODEx_Pos			GPIO_CRH_MODE8_Pos
#define BUS_D2_GPIO_CRx_CNFx_Pos			GPIO_CRH_CNF8_Pos
/* D3 pin */
#define BUS_D3_CRx							CRL
#define BUS_D3_GPIO_CRx_MODEx				GPIO_CRL_MODE7
#define BUS_D3_GPIO_CRx_CNFx				GPIO_CRL_CNF7
#define BUS_D3_GPIO_CRx_MODEx_Pos			GPIO_CRL_MODE7_Pos
#define BUS_D3_GPIO_CRx_CNFx_Pos			GPIO_CRL_CNF7_Pos
/* D4 pin */
#define BUS_D4_CRx							CRL
#define BUS_D4_GPIO_CRx_MODEx				GPIO_CRL_MODE6
#define BUS_D4_GPIO_CRx_CNFx				GPIO_CRL_CNF6
#define BUS_D4_GPIO_CRx_MODEx_Pos			GPIO_CRL_MODE6_Pos
#define BUS_D4_GPIO_CRx_CNFx_Pos			GPIO_CRL_CNF6_Pos
/* D5 pin */
#define BUS_D5_CRx							CRH
#define BUS_D5_GPIO_CRx_MODEx				GPIO_CRH_MODE15
#define BUS_D5_GPIO_CRx_CNFx				GPIO_CRH_CNF15
#define BUS_D5_GPIO_CRx_MODEx_Pos			GPIO_CRH_MODE15_Pos
#define BUS_D5_GPIO_CRx_CNFx_Pos			GPIO_CRH_CNF15_Pos
/* D6 pin */
#define BUS_D6_CRx							CRH
#define BUS_D6_GPIO_CRx_MODEx				GPIO_CRH_MODE14
#define BUS_D6_GPIO_CRx_CNFx				GPIO_CRH_CNF14
#define BUS_D6_GPIO_CRx_MODEx_Pos			GPIO_CRH_MODE14_Pos
#define BUS_D6_GPIO_CRx_CNFx_Pos			GPIO_CRH_CNF14_Pos
/* D7 pin */
#define BUS_D7_CRx							CRH
#define BUS_D7_GPIO_CRx_MODEx				GPIO_CRH_MODE13
#define BUS_D7_GPIO_CRx_CNFx				GPIO_CRH_CNF13
#define BUS_D7_GPIO_CRx_MODEx_Pos			GPIO_CRH_MODE13_Pos
#define BUS_D7_GPIO_CRx_CNFx_Pos			GPIO_CRH_CNF13_Pos

/* Bus line state */
typedef enum
{
	BUS_LINE_RESET = 0U,
	BUS_LINE_SET
} BUS_LineState;

/* Bus data */
typedef struct
{
	BUS_LineState D0LineState;
	BUS_LineState D1LineState;
	BUS_LineState D2LineState;
	BUS_LineState D3LineState;
	BUS_LineState D4LineState;
	BUS_LineState D5LineState;
	BUS_LineState D6LineState;
	BUS_LineState D7LineState;
} BUS_Data;

/* Configure bus to input mode */
void BUS_ToInputMode(void);

/* Read data from the bus */
void BUS_Read(BUS_Data *Data);

/* Configure bus to output mode */
void BUS_ToOutputMode(void);

/* Write data to the bus */
void BUS_Write(BUS_Data Data);

/* Write integer variable to the bus */
void BUS_WriteInteger(uint8_t var);

#endif /* __bus_h */

/* end of bus.h */
