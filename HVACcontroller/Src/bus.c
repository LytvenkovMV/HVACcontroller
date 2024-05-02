
#include "bus.h"


void BUS_ToInputMode(void)
{
	/* Reset control bits for the D0 pin and configure pin's mode as floating input */
	D0_GPIO_Port->BUS_D0_CRx &= ~ (BUS_D0_GPIO_CRx_CNFx | BUS_D0_GPIO_CRx_MODEx);
	D0_GPIO_Port->BUS_D0_CRx |= (0b01 << BUS_D0_GPIO_CRx_CNFx_Pos) | (0b00 << BUS_D0_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D1 pin and configure pin's mode as floating input */
	D1_GPIO_Port->BUS_D1_CRx &= ~ (BUS_D1_GPIO_CRx_CNFx | BUS_D1_GPIO_CRx_MODEx);
	D1_GPIO_Port->BUS_D1_CRx |= (0b01 << BUS_D1_GPIO_CRx_CNFx_Pos) | (0b00 << BUS_D1_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D2 pin and configure pin's mode as floating input */
	D2_GPIO_Port->BUS_D2_CRx &= ~ (BUS_D2_GPIO_CRx_CNFx | BUS_D2_GPIO_CRx_MODEx);
	D2_GPIO_Port->BUS_D2_CRx |= (0b01 << BUS_D2_GPIO_CRx_CNFx_Pos) | (0b00 << BUS_D2_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D3 pin and configure pin's mode as floating input */
	D3_GPIO_Port->BUS_D3_CRx &= ~ (BUS_D3_GPIO_CRx_CNFx | BUS_D3_GPIO_CRx_MODEx);
	D3_GPIO_Port->BUS_D3_CRx |= (0b01 << BUS_D3_GPIO_CRx_CNFx_Pos) | (0b00 << BUS_D3_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D4 pin and configure pin's mode as floating input */
	D4_GPIO_Port->BUS_D4_CRx &= ~ (BUS_D4_GPIO_CRx_CNFx | BUS_D4_GPIO_CRx_MODEx);
	D4_GPIO_Port->BUS_D4_CRx |= (0b01 << BUS_D4_GPIO_CRx_CNFx_Pos) | (0b00 << BUS_D4_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D5 pin and configure pin's mode as floating input */
	D5_GPIO_Port->BUS_D5_CRx &= ~ (BUS_D5_GPIO_CRx_CNFx | BUS_D5_GPIO_CRx_MODEx);
	D5_GPIO_Port->BUS_D5_CRx |= (0b01 << BUS_D5_GPIO_CRx_CNFx_Pos) | (0b00 << BUS_D5_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D6 pin and configure pin's mode as floating input */
	D6_GPIO_Port->BUS_D6_CRx &= ~ (BUS_D6_GPIO_CRx_CNFx | BUS_D6_GPIO_CRx_MODEx);
	D6_GPIO_Port->BUS_D6_CRx |= (0b01 << BUS_D6_GPIO_CRx_CNFx_Pos) | (0b00 << BUS_D6_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D7 pin and configure pin's mode as floating input */
	D7_GPIO_Port->BUS_D7_CRx &= ~ (BUS_D7_GPIO_CRx_CNFx | BUS_D7_GPIO_CRx_MODEx);
	D7_GPIO_Port->BUS_D7_CRx |= (0b01 << BUS_D7_GPIO_CRx_CNFx_Pos) | (0b00 << BUS_D7_GPIO_CRx_MODEx_Pos);
}	



void BUS_Read(BUS_Data *Data)
{
	GPIO_PinState pinState = GPIO_PIN_RESET;

	pinState = HAL_GPIO_ReadPin(D0_GPIO_Port, D0_Pin);
	if (pinState == GPIO_PIN_SET) Data->D0LineState = BUS_LINE_SET; else Data->D0LineState = BUS_LINE_RESET;
	
	pinState = HAL_GPIO_ReadPin(D1_GPIO_Port, D1_Pin);
	if (pinState == GPIO_PIN_SET) Data->D1LineState = BUS_LINE_SET; else Data->D1LineState = BUS_LINE_RESET;
	
	pinState = HAL_GPIO_ReadPin(D2_GPIO_Port, D2_Pin);
	if (pinState == GPIO_PIN_SET) Data->D2LineState = BUS_LINE_SET; else Data->D2LineState = BUS_LINE_RESET;

	pinState = HAL_GPIO_ReadPin(D3_GPIO_Port, D3_Pin);
	if (pinState == GPIO_PIN_SET) Data->D3LineState = BUS_LINE_SET; else Data->D3LineState = BUS_LINE_RESET;

	pinState = HAL_GPIO_ReadPin(D4_GPIO_Port, D4_Pin);
	if (pinState == GPIO_PIN_SET) Data->D4LineState = BUS_LINE_SET; else Data->D4LineState = BUS_LINE_RESET;

	pinState = HAL_GPIO_ReadPin(D5_GPIO_Port, D5_Pin);
	if (pinState == GPIO_PIN_SET) Data->D5LineState = BUS_LINE_SET; else Data->D5LineState = BUS_LINE_RESET;

	pinState = HAL_GPIO_ReadPin(D6_GPIO_Port, D6_Pin);
	if (pinState == GPIO_PIN_SET) Data->D6LineState = BUS_LINE_SET; else Data->D6LineState = BUS_LINE_RESET;

	pinState = HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin);
	if (pinState == GPIO_PIN_SET) Data->D7LineState = BUS_LINE_SET; else Data->D7LineState = BUS_LINE_RESET;
}



void BUS_ToOutputMode(void)
{
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);

	/* Reset control bits for the D0 pin and configure pin's mode as output push-pull */
	D0_GPIO_Port->BUS_D0_CRx &= ~ (BUS_D0_GPIO_CRx_CNFx | BUS_D0_GPIO_CRx_MODEx);
	D0_GPIO_Port->BUS_D0_CRx |= (0b00 << BUS_D0_GPIO_CRx_CNFx_Pos) | (0b01 << BUS_D0_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D1 pin and configure pin's mode as output push-pull */
	D1_GPIO_Port->BUS_D1_CRx &= ~ (BUS_D1_GPIO_CRx_CNFx | BUS_D1_GPIO_CRx_MODEx);
	D1_GPIO_Port->BUS_D1_CRx |= (0b00 << BUS_D1_GPIO_CRx_CNFx_Pos) | (0b01 << BUS_D1_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D2 pin and configure pin's mode as output push-pull */
	D2_GPIO_Port->BUS_D2_CRx &= ~ (BUS_D2_GPIO_CRx_CNFx | BUS_D2_GPIO_CRx_MODEx);
	D2_GPIO_Port->BUS_D2_CRx |= (0b00 << BUS_D2_GPIO_CRx_CNFx_Pos) | (0b01 << BUS_D2_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D3 pin and configure pin's mode as output push-pull */
	D3_GPIO_Port->BUS_D3_CRx &= ~ (BUS_D3_GPIO_CRx_CNFx | BUS_D3_GPIO_CRx_MODEx);
	D3_GPIO_Port->BUS_D3_CRx |= (0b00 << BUS_D3_GPIO_CRx_CNFx_Pos) | (0b01 << BUS_D3_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D4 pin and configure pin's mode as output push-pull */
	D4_GPIO_Port->BUS_D4_CRx &= ~ (BUS_D4_GPIO_CRx_CNFx | BUS_D4_GPIO_CRx_MODEx);
	D4_GPIO_Port->BUS_D4_CRx |= (0b00 << BUS_D4_GPIO_CRx_CNFx_Pos) | (0b01 << BUS_D4_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D5 pin and configure pin's mode as output push-pull */
	D5_GPIO_Port->BUS_D5_CRx &= ~ (BUS_D5_GPIO_CRx_CNFx | BUS_D5_GPIO_CRx_MODEx);
	D5_GPIO_Port->BUS_D5_CRx |= (0b00 << BUS_D5_GPIO_CRx_CNFx_Pos) | (0b01 << BUS_D5_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D6 pin and configure pin's mode as output push-pull */
	D6_GPIO_Port->BUS_D6_CRx &= ~ (BUS_D6_GPIO_CRx_CNFx | BUS_D6_GPIO_CRx_MODEx);
	D6_GPIO_Port->BUS_D6_CRx |= (0b00 << BUS_D6_GPIO_CRx_CNFx_Pos) | (0b01 << BUS_D6_GPIO_CRx_MODEx_Pos);

	/* Reset control bits for the D7 pin and configure pin's mode as output push-pull */
	D7_GPIO_Port->BUS_D7_CRx &= ~ (BUS_D7_GPIO_CRx_CNFx | BUS_D7_GPIO_CRx_MODEx);
	D7_GPIO_Port->BUS_D7_CRx |= (0b00 << BUS_D7_GPIO_CRx_CNFx_Pos) | (0b01 << BUS_D7_GPIO_CRx_MODEx_Pos);
}



void BUS_Write(BUS_Data Data)
{
	if (Data.D0LineState == BUS_LINE_SET) HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_RESET);
	if (Data.D1LineState == BUS_LINE_SET) HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	if (Data.D2LineState == BUS_LINE_SET) HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	if (Data.D3LineState == BUS_LINE_SET) HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	if (Data.D4LineState == BUS_LINE_SET) HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	if (Data.D5LineState == BUS_LINE_SET) HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	if (Data.D6LineState == BUS_LINE_SET) HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	if (Data.D7LineState == BUS_LINE_SET) HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
}



void BUS_WriteInteger(uint8_t data)
{
	if (data & 0x01) HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_RESET);
	if (data & 0x02) HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	if (data & 0x04) HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	if (data & 0x08) HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	if (data & 0x10) HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	if (data & 0x20) HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	if (data & 0x40) HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	if (data & 0x80) HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_SET); else HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
}
