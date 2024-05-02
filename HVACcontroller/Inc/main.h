/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2021 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define TSENS4_Pin GPIO_PIN_0
#define TSENS4_GPIO_Port GPIOC
#define TSENS3_Pin GPIO_PIN_1
#define TSENS3_GPIO_Port GPIOC
#define TSENS2_Pin GPIO_PIN_2
#define TSENS2_GPIO_Port GPIOC
#define TSENS1_Pin GPIO_PIN_3
#define TSENS1_GPIO_Port GPIOC
#define BO7_Pin GPIO_PIN_3
#define BO7_GPIO_Port GPIOA
#define BO6_Pin GPIO_PIN_4
#define BO6_GPIO_Port GPIOA
#define BO5_Pin GPIO_PIN_5
#define BO5_GPIO_Port GPIOA
#define BO4_Pin GPIO_PIN_6
#define BO4_GPIO_Port GPIOA
#define BO3_Pin GPIO_PIN_7
#define BO3_GPIO_Port GPIOA
#define BO2_Pin GPIO_PIN_4
#define BO2_GPIO_Port GPIOC
#define BO1_Pin GPIO_PIN_5
#define BO1_GPIO_Port GPIOC
#define LED_Pin GPIO_PIN_0
#define LED_GPIO_Port GPIOB
#define BI11_Pin GPIO_PIN_2
#define BI11_GPIO_Port GPIOB
#define BI11_EXTI_IRQn EXTI2_IRQn
#define OE1_Pin GPIO_PIN_10
#define OE1_GPIO_Port GPIOB
#define OE2_Pin GPIO_PIN_11
#define OE2_GPIO_Port GPIOB
#define BL_Pin GPIO_PIN_12
#define BL_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_13
#define D7_GPIO_Port GPIOB
#define D6_Pin GPIO_PIN_14
#define D6_GPIO_Port GPIOB
#define D5_Pin GPIO_PIN_15
#define D5_GPIO_Port GPIOB
#define D4_Pin GPIO_PIN_6
#define D4_GPIO_Port GPIOC
#define D3_Pin GPIO_PIN_7
#define D3_GPIO_Port GPIOC
#define D2_Pin GPIO_PIN_8
#define D2_GPIO_Port GPIOC
#define D1_Pin GPIO_PIN_9
#define D1_GPIO_Port GPIOC
#define D0_Pin GPIO_PIN_8
#define D0_GPIO_Port GPIOA
#define E_Pin GPIO_PIN_9
#define E_GPIO_Port GPIOA
#define RW_Pin GPIO_PIN_10
#define RW_GPIO_Port GPIOA
#define RS_Pin GPIO_PIN_11
#define RS_GPIO_Port GPIOA
#define LE1_Pin GPIO_PIN_12
#define LE1_GPIO_Port GPIOA
#define B_Pin GPIO_PIN_10
#define B_GPIO_Port GPIOC
#define A_Pin GPIO_PIN_11
#define A_GPIO_Port GPIOC
#define PUSH_Pin GPIO_PIN_12
#define PUSH_GPIO_Port GPIOC
#define SCL_Pin GPIO_PIN_8
#define SCL_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_9
#define SDA_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
