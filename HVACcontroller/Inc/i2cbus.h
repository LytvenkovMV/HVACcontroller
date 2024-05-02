
#include "stm32f1xx_hal.h"
#include "usdelay.h"



#ifndef __i2cbus_h
#define __i2cbus_h

/* Define control register and control bits for SDA pin */
#define I2CBUS_SDA_CRx							CRH
#define I2CBUS_SDA_GPIO_CRx_MODEx				GPIO_CRH_MODE9
#define I2CBUS_SDA_GPIO_CRx_CNFx				GPIO_CRH_CNF9
#define I2CBUS_SDA_GPIO_CRx_MODEx_Pos			GPIO_CRH_MODE9_Pos
#define I2CBUS_SDA_GPIO_CRx_CNFx_Pos			GPIO_CRH_CNF9_Pos

/* Define 1/2 clock cycle delay */
#define I2CBUS_DELAY()							USDELAY_5us()

/* Define functions to control I2C pins */
#define I2CBUS_SCL_PUT_DOWN()					HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_RESET)
#define I2CBUS_SCL_PUT_UP()						HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_SET)
#define I2CBUS_SDA_PUT_DOWN()					HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_RESET)
#define I2CBUS_SDA_PUT_UP()						HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_SET)

/* I2C bus communication result */
typedef enum
{
	I2CBUS_NACK,
	I2CBUS_ACK
} I2CBUS_Result;

/* Send start condition */
void I2CBUS_SendStart(void);

/* Send stop condition */
void I2CBUS_SendStop(void);

/* Send byte */
I2CBUS_Result I2CBUS_SendByte(uint8_t byte);

/* Receive byte and then send receiver answer to the transmitter */
uint8_t I2CBUS_ReceiveByte(I2CBUS_Result ReceiverAnswer);

#endif /* __i2cbus_h */

/* end of i2cbus.h */
