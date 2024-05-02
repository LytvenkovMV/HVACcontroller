
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */

#include "period_config.h"
#include "bus.h"
#include "led.h"
#include "encoder.h"
#include "hmi.h"
#include "display.h"
#include "setting.h"
#include "input.h"
#include "output.h"
#include "sensor.h"
#include "command.h"
#include "heating.h"
#include "intvent.h"
#include "exvent.h"
#include "protection.h"
#include "regulator.h"
#include "message.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;
DMA_HandleTypeDef hdma_adc1;

RTC_HandleTypeDef hrtc;

TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;

osThreadId defaultTaskHandle;
osThreadId HMIControlTaskHandle;
osThreadId ScanInputsTaskHandle;
osThreadId ScanSensorsTaskHandle;
osThreadId ScanEncoderTaskHandle;
osThreadId ScanAM2320TaskHandle;
osThreadId VentilationTaskHandle;
osThreadId HeatingTaskHandle;
osMessageQId ExVentCmdQueueHandle;
osMessageQId IntVentCmdQueueHandle;
osMessageQId HeatingCmdQueueHandle;
osMessageQId LedQueueHandle;
osMessageQId InputStatesQueueHandle;
osMessageQId SettingValuesQueueHandle;
osMessageQId HeatingStateQueueHandle;
osMessageQId MessageQueueHandle;
osMessageQId HeatingResetQueueHandle;
osMessageQId VentResetQueueHandle;
osMessageQId SensorsQueueHandle;
osMessageQId EncoderCmdQueueHandle;
osMessageQId RXDataQueueHandle;
osMessageQId ADCvaluesQueueHandle;
osMutexId busMutexHandle;
osSemaphoreId RTCinterruptSemHandle;
osSemaphoreId ExternInterruptSemHandle;
osSemaphoreId I2CPeriodElapsedSemHandle;
osSemaphoreId HeatingProcSemHandle;
osSemaphoreId VentilationProcSemHandle;
osSemaphoreId VentAutoCtrlSemHandle;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

SENSOR_ADCvalues glADCvalues;
SENSOR_ADCbuffer glADCbuffer;














/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Variables for current measure */
//uint32_t glCurrentsSendingCnt = 0;
//uint32_t const glCurrentsSendingPeriod = PERIOD_CONF_CURRENTS_SENDING_MS;

//SENSOR_CurrentsStruct glCurrents;
//SENSOR_InstCurrents glInstCurrents;
//uint16_t glUpperThrdIL1 = 1;
//uint16_t glUpperThrdIL3 = 1;


/////////////////////////////HMI_Status glHMIstatus;
/////////////////////////////SENSOR_Values glValues;

PROTECTION_State glProtState = PROTECTION_RELEASED;
REGULATOR_Status glRegulatorStatus;
MESSAGE_ID glMessageID;
INTVENT_CoolingState glCoolingState;
INTVENT_State glIntVentState;
EXVENT_State glExVentState;
uint16_t glcoolingCnt = 0;
uint16_t glupdatingCnt = 0;
uint16_t glprotectionCnt = 0;


									////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////












/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_RTC_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM4_Init(void);
static void MX_ADC2_Init(void);
void StartDefaultTask(void const * argument);
void HMIControl(void const * argument);
void ScanInputs(void const * argument);
void ScanSensors(void const * argument);
void ScanEncoder(void const * argument);
void ScanAM2320(void const * argument);
void Ventilation(void const * argument);
void Heating(void const * argument);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* RTC interrupt callback */
void HAL_RTCEx_RTCEventCallback(RTC_HandleTypeDef *hrtc);

/* External interrupt callback */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

/* Period elapsed callback in non blocking mode */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_RTC_Init();
  MX_USART1_UART_Init();
  MX_TIM4_Init();
  MX_ADC2_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Create the mutex(es) */
  /* definition and creation of busMutex */
  osMutexDef(busMutex);
  busMutexHandle = osMutexCreate(osMutex(busMutex));

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of RTCinterruptSem */
  osSemaphoreDef(RTCinterruptSem);
  RTCinterruptSemHandle = osSemaphoreCreate(osSemaphore(RTCinterruptSem), 1);

  /* definition and creation of ExternInterruptSem */
  osSemaphoreDef(ExternInterruptSem);
  ExternInterruptSemHandle = osSemaphoreCreate(osSemaphore(ExternInterruptSem), 1);

  /* definition and creation of I2CPeriodElapsedSem */
  osSemaphoreDef(I2CPeriodElapsedSem);
  I2CPeriodElapsedSemHandle = osSemaphoreCreate(osSemaphore(I2CPeriodElapsedSem), 1);

  /* definition and creation of HeatingProcSem */
  osSemaphoreDef(HeatingProcSem);
  HeatingProcSemHandle = osSemaphoreCreate(osSemaphore(HeatingProcSem), 1);

  /* definition and creation of VentilationProcSem */
  osSemaphoreDef(VentilationProcSem);
  VentilationProcSemHandle = osSemaphoreCreate(osSemaphore(VentilationProcSem), 1);

  /* definition and creation of VentAutoCtrlSem */
  osSemaphoreDef(VentAutoCtrlSem);
  VentAutoCtrlSemHandle = osSemaphoreCreate(osSemaphore(VentAutoCtrlSem), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityIdle, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of HMIControlTask */
  osThreadDef(HMIControlTask, HMIControl, osPriorityLow, 0, 1000);
  HMIControlTaskHandle = osThreadCreate(osThread(HMIControlTask), NULL);

  /* definition and creation of ScanInputsTask */
  osThreadDef(ScanInputsTask, ScanInputs, osPriorityLow, 0, 128);
  ScanInputsTaskHandle = osThreadCreate(osThread(ScanInputsTask), NULL);

  /* definition and creation of ScanSensorsTask */
  osThreadDef(ScanSensorsTask, ScanSensors, osPriorityLow, 0, 128);
  ScanSensorsTaskHandle = osThreadCreate(osThread(ScanSensorsTask), NULL);

  /* definition and creation of ScanEncoderTask */
  osThreadDef(ScanEncoderTask, ScanEncoder, osPriorityNormal, 0, 128);
  ScanEncoderTaskHandle = osThreadCreate(osThread(ScanEncoderTask), NULL);

  /* definition and creation of ScanAM2320Task */
  osThreadDef(ScanAM2320Task, ScanAM2320, osPriorityHigh, 0, 128);
  ScanAM2320TaskHandle = osThreadCreate(osThread(ScanAM2320Task), NULL);

  /* definition and creation of VentilationTask */
  osThreadDef(VentilationTask, Ventilation, osPriorityNormal, 0, 1000);
  VentilationTaskHandle = osThreadCreate(osThread(VentilationTask), NULL);

  /* definition and creation of HeatingTask */
  osThreadDef(HeatingTask, Heating, osPriorityNormal, 0, 1000);
  HeatingTaskHandle = osThreadCreate(osThread(HeatingTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Create the queue(s) */
  /* definition and creation of ExVentCmdQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(ExVentCmdQueue, 1, COMMAND_ExVentCommand);
  ExVentCmdQueueHandle = osMessageCreate(osMessageQ(ExVentCmdQueue), NULL);

  /* definition and creation of IntVentCmdQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(IntVentCmdQueue, 1, COMMAND_IntVentCommand);
  IntVentCmdQueueHandle = osMessageCreate(osMessageQ(IntVentCmdQueue), NULL);

  /* definition and creation of HeatingCmdQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(HeatingCmdQueue, 1, COMMAND_HeatingCommand);
  HeatingCmdQueueHandle = osMessageCreate(osMessageQ(HeatingCmdQueue), NULL);

  /* definition and creation of LedQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(LedQueue, 16, LED_ChangeQuery);
  LedQueueHandle = osMessageCreate(osMessageQ(LedQueue), NULL);

  /* definition and creation of InputStatesQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(InputStatesQueue, 1, INPUT_States);
  InputStatesQueueHandle = osMessageCreate(osMessageQ(InputStatesQueue), NULL);

  /* definition and creation of SettingValuesQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(SettingValuesQueue, 1, SETTING_Values);
  SettingValuesQueueHandle = osMessageCreate(osMessageQ(SettingValuesQueue), NULL);

  /* definition and creation of HeatingStateQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(HeatingStateQueue, 1, HEATING_State);
  HeatingStateQueueHandle = osMessageCreate(osMessageQ(HeatingStateQueue), NULL);

  /* definition and creation of MessageQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(MessageQueue, 8, MESSAGE_Struct);
  MessageQueueHandle = osMessageCreate(osMessageQ(MessageQueue), NULL);

  /* definition and creation of HeatingResetQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(HeatingResetQueue, 1, uint16_t);
  HeatingResetQueueHandle = osMessageCreate(osMessageQ(HeatingResetQueue), NULL);

  /* definition and creation of VentResetQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(VentResetQueue, 1, uint16_t);
  VentResetQueueHandle = osMessageCreate(osMessageQ(VentResetQueue), NULL);

  /* definition and creation of SensorsQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(SensorsQueue, 1, SENSOR_Values);
  SensorsQueueHandle = osMessageCreate(osMessageQ(SensorsQueue), NULL);

  /* definition and creation of EncoderCmdQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(EncoderCmdQueue, 8, ENCODER_Command);
  EncoderCmdQueueHandle = osMessageCreate(osMessageQ(EncoderCmdQueue), NULL);

  /* definition and creation of RXDataQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(RXDataQueue, 1, AM2320_RXData);
  RXDataQueueHandle = osMessageCreate(osMessageQ(RXDataQueue), NULL);

  /* definition and creation of ADCvaluesQueue */
/* what about the sizeof here??? cd native code */
  osMessageQDef(ADCvaluesQueue, 1, SENSOR_ADCbuffer);
  ADCvaluesQueueHandle = osMessageCreate(osMessageQ(ADCvaluesQueue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
 

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC|RCC_PERIPHCLK_ADC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV4;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}

/* ADC1 init function */
static void MX_ADC1_Init(void)
{

  ADC_MultiModeTypeDef multimode;
  ADC_ChannelConfTypeDef sConfig;

    /**Common config 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 2;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the ADC multi-mode 
    */
  multimode.Mode = ADC_DUALMODE_REGSIMULT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Regular Channel 
    */
  sConfig.Channel = ADC_CHANNEL_10;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Regular Channel 
    */
  sConfig.Channel = ADC_CHANNEL_12;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* ADC2 init function */
static void MX_ADC2_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Common config 
    */
  hadc2.Instance = ADC2;
  hadc2.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc2.Init.ContinuousConvMode = DISABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion = 2;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Regular Channel 
    */
  sConfig.Channel = ADC_CHANNEL_11;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure Regular Channel 
    */
  sConfig.Channel = ADC_CHANNEL_13;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* RTC init function */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime;
  RTC_DateTypeDef DateToUpdate;

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

    /**Initialize RTC Only 
    */
  hrtc.Instance = RTC;
  hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
  hrtc.Init.OutPut = RTC_OUTPUTSOURCE_NONE;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* Restore date */
  HMI_RestoreDate(&hrtc);

  /* Return */
  return;

  /* USER CODE END RTC_Init 2 */

    /**Initialize RTC and set the Time and Date 
    */
  sTime.Hours = 12;
  sTime.Minutes = 0;
  sTime.Seconds = 0;

  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
  /* USER CODE BEGIN RTC_Init 3 */

  /* USER CODE END RTC_Init 3 */

  DateToUpdate.WeekDay = RTC_WEEKDAY_WEDNESDAY;
  DateToUpdate.Month = RTC_MONTH_JANUARY;
  DateToUpdate.Date = 1;
  DateToUpdate.Year = 20;

  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BIN) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
  /* USER CODE BEGIN RTC_Init 4 */

  /* USER CODE END RTC_Init 4 */

}

/* TIM4 init function */
static void MX_TIM4_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 36;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 10000;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, BO7_Pin|BO6_Pin|BO5_Pin|BO4_Pin 
                          |BO3_Pin|E_Pin|RW_Pin|RS_Pin 
                          |LE1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, BO2_Pin|BO1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_Pin|OE1_Pin|OE2_Pin|SCL_Pin 
                          |SDA_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(BL_GPIO_Port, BL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BO7_Pin BO6_Pin BO5_Pin BO4_Pin 
                           BO3_Pin LE1_Pin */
  GPIO_InitStruct.Pin = BO7_Pin|BO6_Pin|BO5_Pin|BO4_Pin 
                          |BO3_Pin|LE1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BO2_Pin BO1_Pin */
  GPIO_InitStruct.Pin = BO2_Pin|BO1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_Pin OE1_Pin OE2_Pin SCL_Pin 
                           SDA_Pin */
  GPIO_InitStruct.Pin = LED_Pin|OE1_Pin|OE2_Pin|SCL_Pin 
                          |SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : BI11_Pin */
  GPIO_InitStruct.Pin = BI11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BI11_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BL_Pin */
  GPIO_InitStruct.Pin = BL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BL_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : D7_Pin D6_Pin D5_Pin */
  GPIO_InitStruct.Pin = D7_Pin|D6_Pin|D5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : D4_Pin D3_Pin D2_Pin D1_Pin 
                           B_Pin A_Pin PUSH_Pin */
  GPIO_InitStruct.Pin = D4_Pin|D3_Pin|D2_Pin|D1_Pin 
                          |B_Pin|A_Pin|PUSH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : D0_Pin */
  GPIO_InitStruct.Pin = D0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(D0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : E_Pin RW_Pin RS_Pin */
  GPIO_InitStruct.Pin = E_Pin|RW_Pin|RS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

}

/* USER CODE BEGIN 4 */

void HAL_RTCEx_RTCEventCallback(RTC_HandleTypeDef *hrtc)
{
	/* Private variables */
	static portBASE_TYPE xHigherPriorityTaskWoken;
	xHigherPriorityTaskWoken = pdFALSE;

	/* Give RTC interrupt semaphore */
	xSemaphoreGiveFromISR(RTCinterruptSemHandle, &xHigherPriorityTaskWoken);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	/* Private variables */
	static portBASE_TYPE xHigherPriorityTaskWoken;
	xHigherPriorityTaskWoken = pdFALSE;


	/* External over heating protection */
	/* If interrupt from pin 2 */
	if (GPIO_Pin == GPIO_PIN_2)
	{
		/* Trip ventilation */
		INTVENT_TurnOffHeatersFromIRQ();

		/* Give external interrupt semaphore */
		xSemaphoreGiveFromISR(ExternInterruptSemHandle, &xHigherPriorityTaskWoken);
	}
}

/* USER CODE END 4 */

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */ 
}

/* HMIControl function */
void HMIControl(void const * argument)
{
  /* USER CODE BEGIN HMIControl */

	/* Create and initialize the variable necessary for the system function vTaskDelayUntil() */
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	/* Create private variables */
	portBASE_TYPE xVentAutoCtrlSemStatus = pdPASS;
	portBASE_TYPE xEncoderCmdQueueStatus = pdFAIL;
	portBASE_TYPE xMessageQueueStatus = pdFAIL;
	portBASE_TYPE xLedQueueStatus = pdFAIL;
	SETTING_Values CurrSettingValues;
	ENCODER_Command EncoderCommand;
	MESSAGE_Struct Message;
	LED_States LEDstates;
	LED_ChangeQuery LedChangeQuery;
	HMI_Status HMIstatus;
	uint16_t displayReturnCnt = 0;
	uint8_t cycleCnt = 0;

	/* Load settings from flash */
	SETTING_Load(&CurrSettingValues);

	/* Send loaded setting values to the queue */
	xQueueOverwrite(SettingValuesQueueHandle, &CurrSettingValues);

	/* Turn on RTC second interrupt */
	HAL_RTCEx_SetSecond_IT(&hrtc);

	/***** START OF USING THE BUS MUTEX *****/
	/* Take the bus mutex and switch the bus to output mode */
	xSemaphoreTake(busMutexHandle, portMAX_DELAY);
	BUS_ToOutputMode();

	/* Initialize display and create the custom characters */
	DISPLAY_Init();

	/* Initialize LEDs */
	LED_Init(&LEDstates);

	/* Switch the bus to input mode and give mutex */
	BUS_ToInputMode();
	xSemaphoreGive(busMutexHandle);
	/***** END OF USING THE BUS MUTEX *****/

	/* Initialize HMI */
	HMI_OpenInitial(&HMIstatus);

	/* Reset semaphore */
	xSemaphoreTake(VentAutoCtrlSemHandle, portMAX_DELAY);

	/* Infinite loop */
	for(;;)
	{
		/* Update xLastWakeTime variable */
		xLastWakeTime = xTaskGetTickCount();

		/* Do 5 cycles every 1 second */
		/* Begin first cycle when RTC second interrupt occurs (every 1 second) */
		if (cycleCnt == 0)
		{
			/* Wait for RTC second interrupt semaphore */
			xSemaphoreTake(RTCinterruptSemHandle, portMAX_DELAY);

			/* Increment the display return counter */
			if (displayReturnCnt < PERIOD_CONF_DISPLAY_RETURN_S) displayReturnCnt ++;

			/* Save current date in the backup registers */
			HMI_SaveDate(&hrtc);
		}

		/* If this is not the last cycle wait 200 milliseconds */
		if (cycleCnt < 4) vTaskDelayUntil(&xLastWakeTime, 200);



		/************************************************************************ HMI CONTROL ************************************************************************/

		/* Check the encoder command queue */
		xEncoderCmdQueueStatus = xQueueReceive(EncoderCmdQueueHandle, &EncoderCommand, 0);

		/* Do while queue isn't empty */
		while (xEncoderCmdQueueStatus == pdPASS)
		{
			/* If this is the first command after return display to the initial state, turn on the display back light */
			if (displayReturnCnt >= PERIOD_CONF_DISPLAY_RETURN_S)
			{
				DISPLAY_TurnOnBackLight();
			}
			/* Else handle command from the encoder */
			else
			{
				switch (HMIstatus.ScreenType)
				{
					case HMI_INITIAL_SCREEN: if (EncoderCommand == ENCODER_CMD_PUSH) HMI_OpenMenu(&HMIstatus);	break;
					case HMI_MESSAGE_SCREEN: if (EncoderCommand == ENCODER_CMD_PUSH) HMI_ClearMessage(&HMIstatus, &Message, HeatingResetQueueHandle, VentResetQueueHandle); break;
					case HMI_MENU_SCREEN: HMI_HandleMenu(&EncoderCommand, &HMIstatus, &CurrSettingValues, SettingValuesQueueHandle, &hrtc); break;
				}
			}

			/* Reset the display return counter */
			displayReturnCnt = 0;

			/* Check the encoder command queue */
			xEncoderCmdQueueStatus = xQueueReceive(EncoderCmdQueueHandle, &EncoderCommand, 0);
		}

		/* Handle messages */
		if (HMIstatus.ScreenType != HMI_MESSAGE_SCREEN)
		{
			/* Check the message queue and if new message present, open it */
			xMessageQueueStatus = xQueueReceive(MessageQueueHandle, &Message, 0);
			if (xMessageQueueStatus == pdPASS)
			{
				HMI_OpenMessage(&HMIstatus, &Message);
			}
		}

		/* Turn off ventilation auto control if necessary */
		xVentAutoCtrlSemStatus = xSemaphoreTake(VentAutoCtrlSemHandle, 0);
		if (xVentAutoCtrlSemStatus == pdPASS) HMI_TurnOffVentAutoCtrl(&CurrSettingValues, SettingValuesQueueHandle);


		/* If the display return time has elapsed */
		if (displayReturnCnt >= PERIOD_CONF_DISPLAY_RETURN_S)
		{
			/* If the menu is open, return to the initial screen */
			if (HMIstatus.ScreenType == HMI_MENU_SCREEN) HMI_OpenInitial(&HMIstatus);

			/* Turn off the display back light */
			DISPLAY_TurnOffBackLight();
		}
		/*************************************************************************************************************************************************************/



		/******************************************************************* UPDATE DISPLAY AND LEDs *****************************************************************/

		/***** START OF USING THE BUS MUTEX *****/
		/* Take the bus mutex and switch the bus to output mode */
		xSemaphoreTake(busMutexHandle, portMAX_DELAY);
		BUS_ToOutputMode();

		/* Update display */
		/* If HMI changed, update display immediately */
		if (HMIstatus.Updating == HMI_UPDATED)
		{
			switch (HMIstatus.ScreenType)
			{
				case HMI_INITIAL_SCREEN:	DISPLAY_ShowInitialScreen(&HMIstatus, HeatingStateQueueHandle, SensorsQueueHandle, &hrtc);							break;
				case HMI_MENU_SCREEN:		DISPLAY_ShowMenuScreen(&HMIstatus, SettingValuesQueueHandle, InputStatesQueueHandle, SensorsQueueHandle, &hrtc);	break;
				case HMI_MESSAGE_SCREEN:	DISPLAY_ShowMessageScreen(&HMIstatus);																				break;
			}

			HMIstatus.Updating = HMI_NOT_UPDATED;
		}
		/* Else update display 2 times every second */
		else
		{
			if (cycleCnt == 0)
			{
				switch (HMIstatus.ScreenType)
				{
					case HMI_INITIAL_SCREEN:	DISPLAY_ShowInitialScreen(&HMIstatus, HeatingStateQueueHandle, SensorsQueueHandle, &hrtc);							break;
					case HMI_MENU_SCREEN:		DISPLAY_ShowMenuScreen(&HMIstatus, SettingValuesQueueHandle, InputStatesQueueHandle, SensorsQueueHandle, &hrtc);	break;
					default:;
				}
			}

			if (cycleCnt == 2)
			{
				switch (HMIstatus.ScreenType)
				{
					case HMI_INITIAL_SCREEN:	DISPLAY_HideColonSymbol();																							break;
					case HMI_MENU_SCREEN:		DISPLAY_ShowMenuScreen(&HMIstatus, SettingValuesQueueHandle, InputStatesQueueHandle, SensorsQueueHandle, &hrtc);	break;
					default:;
				}
			}
		}

		/* Update LEDs */
		/* Check the LED queue */
		xLedQueueStatus = xQueueReceive(LedQueueHandle, &LedChangeQuery, 0);

		/* Do while queue isn't empty */
		while (xLedQueueStatus == pdPASS)
		{
			/* Handle LED change query */
			LED_HandleQuery(LedChangeQuery, &LEDstates);
			xLedQueueStatus = xQueueReceive(LedQueueHandle, &LedChangeQuery, 0);
		}

		/* Switch the bus to input mode and give mutex */
		BUS_ToInputMode();
		xSemaphoreGive(busMutexHandle);
		/***** END OF USING THE BUS MUTEX *****/
		/*************************************************************************************************************************************************************/



		/* Increment or reset the cycle counter */
		if (cycleCnt < 5) cycleCnt ++;
		else cycleCnt = 0;
	}

  /* USER CODE END HMIControl */
}

/* ScanInputs function */
void ScanInputs(void const * argument)
{
  /* USER CODE BEGIN ScanInputs */

	/* Create and initialize the variable necessary for the system function vTaskDelayUntil() */
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	/* Create private variables */
	INPUT_States CurrStates, PrevStates;
	COMMAND_Commands Commands;

	/* Take the bus mutex, switch the bus to input mode, scan inputs and give mutex*/
	xSemaphoreTake(busMutexHandle, portMAX_DELAY);
	BUS_ToInputMode();

	/***** START OF CRITICAL SECTION *****/
	taskENTER_CRITICAL();
	INPUT_GetStates(&PrevStates);
	xSemaphoreGive(busMutexHandle);
	taskEXIT_CRITICAL();
	/****** END OF CRITICAL SECTION ******/

	/* Send input states to the queue */
	xQueueOverwrite(InputStatesQueueHandle, &CurrStates);

	/* Delay for the scan period */
	vTaskDelay(PERIOD_CONF_INPUTS_SCAN_MS);

	/* Infinite loop */
	for(;;)
	{
		/* Take the bus mutex, switch the bus to input mode, scan inputs and give mutex*/
		xSemaphoreTake(busMutexHandle, portMAX_DELAY);
		BUS_ToInputMode();

		/***** START OF CRITICAL SECTION *****/
		taskENTER_CRITICAL();
		INPUT_GetStates(&CurrStates);
		xSemaphoreGive(busMutexHandle);
		taskEXIT_CRITICAL();
		/****** END OF CRITICAL SECTION ******/

		/* Send input states to the queue */
		xQueueOverwrite(InputStatesQueueHandle, &CurrStates);

		/* Get commands */
		INPUT_GetCommands(&Commands, PrevStates, CurrStates);

		/* Send commands to the corresponding queues if necessary */
		if (Commands.ExVentStatus	== COMMAND_CHANGED) xQueueOverwrite(ExVentCmdQueueHandle, &Commands.ExVentCommand);
		if (Commands.IntVentStatus	== COMMAND_CHANGED) xQueueOverwrite(IntVentCmdQueueHandle, &Commands.IntVentCommand);
		if (Commands.HeatingStatus	== COMMAND_CHANGED) xQueueOverwrite(HeatingCmdQueueHandle, &Commands.HeatingCommand);

		/* Save current input states for use in the new cycle */
		PrevStates = CurrStates;

		/* Delay for scan period */
		vTaskDelayUntil(&xLastWakeTime, PERIOD_CONF_INPUTS_SCAN_MS);
	}

  /* USER CODE END ScanInputs */
}

/* ScanSensors function */
void ScanSensors(void const * argument)
{
  /* USER CODE BEGIN ScanSensors */

  	/* Create and initialize the variable necessary for the system function vTaskDelayUntil() */
  	portTickType xLastWakeTime;
  	xLastWakeTime = xTaskGetTickCount();

	/* Create private variables */
  	SENSOR_Values Values;
  	AM2320_State AM2320State;

  	/* Initialize AM2320 sensor state */
  	AM2320_Init(&AM2320State);

  	/* Calibrate ADC */
	osDelay(500);
	SENSOR_CalibrateADC(&hadc1, &hadc2);
	osDelay(500);

	/* Start the timer used to start the ADC */
	HAL_TIM_Base_Start_IT(&htim4);

	osDelay(1000);

	/* Update sensor values */
	SENSOR_UpdateValues(&Values, &AM2320State, RXDataQueueHandle, ADCvaluesQueueHandle);
	vTaskDelay(PERIOD_CONF_SENSORS_SCAN_MS);

	/* Infinite loop */
	for(;;)
	{
		/* Update sensor values */
		SENSOR_UpdateValues(&Values, &AM2320State, RXDataQueueHandle, ADCvaluesQueueHandle);

		/* Send values to the queue */
		xQueueOverwrite(SensorsQueueHandle, &Values);

		/* Give semaphores to wake up heating and ventilation processes */
		xSemaphoreGive(HeatingProcSemHandle);
		xSemaphoreGive(VentilationProcSemHandle);

		/* Delay for scan period */
		vTaskDelayUntil(&xLastWakeTime, PERIOD_CONF_SENSORS_SCAN_MS);
	}

  /* USER CODE END ScanSensors */
}

/* ScanEncoder function */
void ScanEncoder(void const * argument)
{
  /* USER CODE BEGIN ScanEncoder */

	/* Create private variables */
	ENCODER_State PrevState, CurrState;
	ENCODER_Command Command;
	ENCODER_Status Status = ENCODER_NOT_CHANGED;
	uint16_t pushCnt = 0;

	/* Initialize encoder state */
	CurrState.AB = ENCODER_AB_00;
	CurrState.Push = ENCODER_PUSH_LOW;

	/* Infinite loop */
	for(;;)
	{
		/* Save current state to use in new cycle */
		PrevState = CurrState;

		/***** START OF CRITICAL SECTION *****/
		/* Update current state */
		taskENTER_CRITICAL();
		CurrState = ENCODER_GetState();
		taskEXIT_CRITICAL();
		/****** END OF CRITICAL SECTION ******/

		/* Get command from the encoder */
		Status = ENCODER_GetCommand(&Command, &PrevState, &CurrState, &pushCnt);

		/* If a new command present send it to the queue */
		if (Status == ENCODER_CHANGED) xQueueSend(EncoderCmdQueueHandle, &Command, portMAX_DELAY);

		/* Delay for encoder scan period */
		osDelay(PERIOD_CONF_ENCODER_SCAN_MS);
	}

  /* USER CODE END ScanEncoder */
}

/* ScanAM2320 function */
void ScanAM2320(void const * argument)
{
  /* USER CODE BEGIN ScanAM2320 */

	/* Create and initialize the variable necessary for the system function vTaskDelayUntil() */
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	/* Create private variables */
	I2CBUS_Result I2CBusTXResult = I2CBUS_NACK, I2CBusRXResult = I2CBUS_NACK;
	AM2320_RXData RXData;
	uint8_t buffer[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	osDelay(PERIOD_CONF_AM2320_SCAN_MS);

	/* Infinite loop */
	for(;;)
	{
		/* Wake AM2320 sensor */
		AM2320_Wake(AM2320_ADDRESS);

		/* Wait 1 millisecond */
		vTaskDelay(1);

		/* Transmit query to AM2320 sensor */
		I2CBusTXResult = AM2320_TransmitQuery(AM2320_ADDRESS);

		/* If transmission is OK */
		if (I2CBusTXResult == I2CBUS_ACK)
		{
			/* Wait 3 milliseconds */
			vTaskDelay(3);

			/* Receive data from AM2320 sensor */
			I2CBusRXResult = AM2320_ReceiveData(AM2320_ADDRESS, buffer);

			/* If receiving is OK */
			if (I2CBusRXResult == I2CBUS_ACK)
			{
				RXData.functionCode     = buffer[0];
				RXData.numberOfBytes    = buffer[1];
				RXData.humidityHighByte = buffer[2];
				RXData.humidityLowByte  = buffer[3];
				RXData.tempHighByte     = buffer[4];
				RXData.tempLowByte      = buffer[5];
				RXData.crcLowByte       = buffer[6];
				RXData.crcHighByte      = buffer[7];

				/* Send RXData to the queue */
				xQueueOverwrite(RXDataQueueHandle, &RXData);
			}
		}

		vTaskDelayUntil(&xLastWakeTime, PERIOD_CONF_AM2320_SCAN_MS);
	}

  /* USER CODE END ScanAM2320 */
}

/* Ventilation function */
void Ventilation(void const * argument)
{
  /* USER CODE BEGIN Ventilation */

	/* Private variables */
	SETTING_Values SettingValues;
	SENSOR_Values SensorCurrValues, SensorPrevValues;
	PROTECTION_State ProtState = PROTECTION_RELEASED;
	REGULATOR_Status RegulatorStatus;
	MESSAGE_ID MessageID;
	INTVENT_State IntVentState;
	INTVENT_CoolingState CoolingState = INTVENT_COOLING_NOT_COMPLETE;
	EXVENT_State ExVentState;
	uint16_t coolingCnt = 0;
	uint16_t updatingCnt = 0;
	uint16_t protectionCnt = 0;

	/* Wait for the sensors and the settings are ready */
	vTaskDelay(2000);

	/* Initializations */
	INTVENT_InitState(&IntVentState);
	EXVENT_InitState(&ExVentState);
	REGULATOR_Init(&RegulatorStatus);

	/* Update sensor values and setting values */
	do
	{
		IntVentState.UpdatingStatus = INTVENT_UpdateData(&MessageID, &SensorCurrValues, &SettingValues, SensorsQueueHandle, SettingValuesQueueHandle, &updatingCnt);
		vTaskDelay(PERIOD_CONF_VENTILATION);
	}
	while ((IntVentState.UpdatingStatus) != INTVENT_UPDATING_OK);

	/* Reset semaphore */
	xSemaphoreTake(ExternInterruptSemHandle, portMAX_DELAY);

	/* Infinite loop */
	for(;;)
	{





		//////////////////////////////////////////////////////////////////////////////////////////////////////////////


		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);


		glProtState = ProtState;
		glRegulatorStatus = RegulatorStatus;
		glMessageID = MessageID;
		glCoolingState = CoolingState;
		glIntVentState = IntVentState;
		glExVentState = ExVentState;
		glcoolingCnt = coolingCnt;
		glupdatingCnt = updatingCnt;
		glprotectionCnt = protectionCnt;


		                       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////










		/* Wait for process semaphore */
		xSemaphoreTake(VentilationProcSemHandle, 1000);



		/************************************************************************ UPDATE DATA ***********************************************************************/

		/* Save current sensor values */
		SensorPrevValues = SensorCurrValues;

		/* Update sensor values and setting values */
		IntVentState.UpdatingStatus = INTVENT_UpdateData(&MessageID, &SensorCurrValues, &SettingValues, SensorsQueueHandle, SettingValuesQueueHandle, &updatingCnt);

		/* Update auto control time */
		IntVentState.AutoCtrlTime = INTVENT_GetAutoCtrlTime(&SettingValues, &hrtc);

		/*************************************************************************************************************************************************************/



		/***************************************************************** INTAKE VENTILATION CONTROL ****************************************************************/

		/* Heaters cooling procedure */
		/* If intake ventilation off */
		if (IntVentState.CurrMode == INTVENT_OFF)
		{
			/* If fan on */
			if (IntVentState.FanState == INTVENT_FAN_ON)
			{
				switch (IntVentState.CoolingRequest)
				{
				case INTVENT_COOLING_NOT_REQUIRED:
					/* Turn off fan */
					INTVENT_TurnOffFan();
					IntVentState.FanState = INTVENT_FAN_OFF;
					break;

				case INTVENT_COOLING_REQUIRED:
					/* Get cooling state */
					CoolingState = INTVENT_GetCoolingState(&SettingValues, &coolingCnt, PERIOD_CONF_VENTILATION);

					/* If cooling complete, turn off fan and reset the cooling request */
					if (CoolingState == INTVENT_COOLING_COMPLETE)
					{
						INTVENT_TurnOffFan();
						IntVentState.FanState = INTVENT_FAN_OFF;
						IntVentState.CoolingRequest = INTVENT_COOLING_NOT_REQUIRED;
					}
					break;

				default:;
				}
			}
		}


		/* If ventilation fail, try to reset ventilation process */
		if (IntVentState.ProcessState != INTVENT_OK) INTVENT_Reset(&IntVentState, VentResetQueueHandle, LedQueueHandle);

		/* If ventilation OK */
		else
		{
			/* If new data is not available, trip ventilation emergency and send message to the queue */
			if ((IntVentState.UpdatingStatus) != INTVENT_UPDATING_OK)
			{
				INTVENT_Trip(&IntVentState, LedQueueHandle);
				MESSAGE_Send(MessageID, MessageQueueHandle, &hrtc, 1000);
			}

			/* If new data is available */
			else
			{
				/* Store current mode */
				IntVentState.PrevMode = IntVentState.CurrMode;

				/* Update ventilation mode */
				INTVENT_UpdateMode(&IntVentState, &SettingValues, IntVentCmdQueueHandle, &hrtc);

				switch (IntVentState.CurrMode)
				{
				case INTVENT_OFF:
					/* Turn off ventilation if necessary */
					if (IntVentState.CurrMode != IntVentState.PrevMode) INTVENT_TurnOff(LedQueueHandle);
					break;

				case INTVENT_ON:
					/* Turn on ventilation if necessary */
					if (IntVentState.CurrMode != IntVentState.PrevMode)
					{
						INTVENT_TurnOn(&SettingValues, LedQueueHandle);
						protectionCnt = 0;
						coolingCnt = 0;
					}
					break;

				case INTVENT_ON_WITH_HEAT:
					/* Execute the protection process */
					ProtState = PROTECTION_Ventilation(&MessageID, &SettingValues, &SensorCurrValues, &SensorPrevValues, PERIOD_CONF_VENTILATION, &protectionCnt, ExternInterruptSemHandle);

					/* If protection tripped, trip ventilation emergency and give a semaphore that turns off auto control */
					if (ProtState != PROTECTION_RELEASED)
					{
						INTVENT_Trip(&IntVentState, LedQueueHandle);
						xSemaphoreGive(VentAutoCtrlSemHandle);
						MESSAGE_Send(MessageID, MessageQueueHandle, &hrtc, 1000);
					}

					/* If protection released */
					else
					{
						/* Turn on ventilation if necessary */
						if (IntVentState.CurrMode != IntVentState.PrevMode)
						{
							INTVENT_TurnOn(&SettingValues, LedQueueHandle);
							protectionCnt = 0;
							coolingCnt = 0;
						}

						/* Regulate temperature */
						REGULATOR_Ventilation(&RegulatorStatus, &SettingValues, &SensorCurrValues);

						/* If regulator fail, trip ventilation emergency */
						if (RegulatorStatus.State != REGULATOR_OK)
						{
							INTVENT_Trip(&IntVentState, LedQueueHandle);
							MessageID = MESSAGE_27;
							MESSAGE_Send(MessageID, MessageQueueHandle, &hrtc, 1000);
						}

						/* If regulator OK, turn on/off heaters if necessary */
						else
						{
							switch(RegulatorStatus.OutputCommand)
							{
								case REGULATOR_TURN_OFF_CMD:	INTVENT_TurnOffHeaters();				break;
								case REGULATOR_TURN_ON_CMD:		INTVENT_TurnOnHeaters(&SettingValues);	break;
								default:;
							}
						}
					}
					break;

				default:;
				}
			}
		}

		/*************************************************************************************************************************************************************/



		/**************************************************************** EXHAUST VENTILATION CONTROL ****************************************************************/

		/* Store current mode */
		ExVentState.PrevMode = ExVentState.CurrMode;

		/* Update ventilation mode */
		EXVENT_UpdateMode(&ExVentState, IntVentState, &SettingValues, ExVentCmdQueueHandle);

		if (ExVentState.CurrMode != ExVentState.PrevMode)
		{
			switch (ExVentState.CurrMode)
			{
			case EXVENT_OFF:
				EXVENT_TurnOff(LedQueueHandle);
				ExVentState.CurrMode = EXVENT_OFF;
			break;

			case EXVENT_ON:
				EXVENT_TurnOn(LedQueueHandle);
				ExVentState.CurrMode = EXVENT_ON;
			break;

			default:;
			}
		}

		/*************************************************************************************************************************************************************/
	}

  /* USER CODE END Ventilation */
}

/* Heating function */
void Heating(void const * argument)
{
  /* USER CODE BEGIN Heating */

	/* Private variables */
	SETTING_Values SettingValues;
	SENSOR_Values SensorCurrValues, SensorPrevValues;
	PROTECTION_State ProtState = PROTECTION_RELEASED;
	REGULATOR_Status RegulatorStatus;
	MESSAGE_ID MessageID;
	HEATING_UpdatingStatus UpdatingStatus = HEATING_UPDATING_FAIL;
	HEATING_CoolingState CoolingState = HEATING_COOLING_NOT_COMPLETE;
	HEATING_State HeatingState;
	uint16_t coolingCnt = 0;
	uint16_t updatingCnt = 0;
	uint16_t protectionCnt = 0;

	HEATING_InitState(&HeatingState);
	REGULATOR_Init(&RegulatorStatus);

	/* Wait for the sensors and the settings are ready */
	vTaskDelay(2000);

	/* Update data */
	do
	{
		UpdatingStatus = HEATING_UpdateData(&MessageID, &SensorCurrValues, &SettingValues, SensorsQueueHandle, SettingValuesQueueHandle, &updatingCnt);
		vTaskDelay(PERIOD_CONF_HEATING);
	}
	while (UpdatingStatus != HEATING_UPDATING_OK);

	/* Infinite loop */
	for(;;)
	{

		/* Wait for process semaphore */
		xSemaphoreTake(HeatingProcSemHandle, 1000);



		/************************************************************************ UPDATE DATA ***********************************************************************/

		/* Save current data */
		SensorPrevValues = SensorCurrValues;

		/* Update data */
		UpdatingStatus = HEATING_UpdateData(&MessageID, &SensorCurrValues, &SettingValues, SensorsQueueHandle, SettingValuesQueueHandle, &updatingCnt);

		/*************************************************************************************************************************************************************/



		/********************************************************************** HEATING CONTROL **********************************************************************/

		/* If heating mode is COOLING */
		if (HeatingState.CurrMode == HEATING_COOLING)
		{
			/* Cool down heaters, turn off pump and change heating mode to OFF */
			CoolingState = HEATING_CoolDown(&SettingValues, &coolingCnt, PERIOD_CONF_HEATING);
			if (CoolingState == HEATING_COOLING_COMPLETE) HeatingState.CurrMode = HEATING_OFF;
		}

		/* Send heating state to the corresponding queue */
		xQueueOverwrite(HeatingStateQueueHandle, &HeatingState);

		/* If heating fail, try to reset heating process */
		if (HeatingState.ProcessState != HEATING_OK) HEATING_Reset(&HeatingState, HeatingResetQueueHandle, LedQueueHandle);

		/* If heating OK */
		else
		{
			/* If new data is not available, trip heating emergency and send message to the queue */
			if (UpdatingStatus != HEATING_UPDATING_OK)
			{
				HEATING_Trip(&HeatingState, LedQueueHandle);
				MESSAGE_Send(MessageID, MessageQueueHandle, &hrtc, 1000);
			}

			/* If new data is available */
			else
			{
				/* Store current mode */
				HeatingState.PrevMode = HeatingState.CurrMode;

				/* Update heating mode */
				HEATING_UpdateMode(&HeatingState, &SettingValues, HeatingCmdQueueHandle, &hrtc);

				switch (HeatingState.CurrMode)
				{
				/* Case heating turned off do nothing */
				case HEATING_OFF:; break;

				/* Case heating is cooling */
				case HEATING_COOLING:
					/* If heating was on, turn it off */
					if ((HeatingState.PrevMode == HEATING_COMFORT) || (HeatingState.PrevMode == HEATING_ECO) || (HeatingState.PrevMode == HEATING_FRZ))
					{
						HEATING_TurnOff(LedQueueHandle);
					}
					break;

				/* Case heating mode is COMFORT, ECO or FRZ */
				default:
					/* Execute the protection process */
					ProtState = PROTECTION_Heating(&MessageID, &SettingValues, &SensorCurrValues, &SensorPrevValues, PERIOD_CONF_HEATING, &protectionCnt);

					/* If protection tripped, trip heating emergency */
					if (ProtState != PROTECTION_RELEASED)
					{
						HEATING_Trip(&HeatingState, LedQueueHandle);
						MESSAGE_Send(MessageID, MessageQueueHandle, &hrtc, 1000);
					}

					/* If protection released */
					else
					{
						/* If heating has been turned off or cooled, turn it on */
						if ((HeatingState.PrevMode == HEATING_OFF) || (HeatingState.PrevMode == HEATING_COOLING))
						{
							HEATING_TurnOn(&SettingValues, LedQueueHandle);
							protectionCnt = 0;
							coolingCnt = 0;
						}

						/* Regulate temperature */
						REGULATOR_Heating(&RegulatorStatus, HeatingState.CurrMode, &SettingValues, &SensorCurrValues);

						/* If regulator fail, trip heating emergency */
						if (RegulatorStatus.State != REGULATOR_OK)
						{
							HEATING_Trip(&HeatingState, LedQueueHandle);
							MessageID = MESSAGE_26;
							MESSAGE_Send(MessageID, MessageQueueHandle, &hrtc, 1000);
						}

						/* If regulator OK, turn on/off heaters if necessary */
						else
						{
							switch(RegulatorStatus.OutputCommand)
							{
								case REGULATOR_TURN_OFF_CMD:	HEATING_TurnOffHeaters();				break;
								case REGULATOR_TURN_ON_CMD:		HEATING_TurnOnHeaters(&SettingValues);	break;
								default:;
							}
						}
					}
				}
			}
		}

		/*************************************************************************************************************************************************************/
	}

  /* USER CODE END Heating */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM2 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM2) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

	/* If TIM4 period elapsed */
	if (htim->Instance == TIM4)
	{
		/* Private variables */
		static portBASE_TYPE xHigherPriorityTaskWoken;
		xHigherPriorityTaskWoken = pdFALSE;

		/* Shift ADC buffer to the left */
		for (uint16_t i = 0; i < (SENSOR_ADC_BUFFER_SIZE - 1); i ++)
		{
			glADCbuffer.BUFFERTSENS1[i] = glADCbuffer.BUFFERTSENS1[i + 1];
			glADCbuffer.BUFFERTSENS2[i] = glADCbuffer.BUFFERTSENS2[i + 1];
			glADCbuffer.BUFFERTSENS3[i] = glADCbuffer.BUFFERTSENS3[i + 1];
			glADCbuffer.BUFFERTSENS4[i] = glADCbuffer.BUFFERTSENS4[i + 1];
		}

		/* Write ADC values to the end of the ADC buffer */
		glADCbuffer.BUFFERTSENS1[SENSOR_ADC_BUFFER_SIZE - 1] = glADCvalues.TSENS1;
		glADCbuffer.BUFFERTSENS2[SENSOR_ADC_BUFFER_SIZE - 1] = glADCvalues.TSENS2;
		glADCbuffer.BUFFERTSENS3[SENSOR_ADC_BUFFER_SIZE - 1] = glADCvalues.TSENS3;
		glADCbuffer.BUFFERTSENS4[SENSOR_ADC_BUFFER_SIZE - 1] = glADCvalues.TSENS4;

		/* Send ADC buffer to the queue */
		xQueueOverwriteFromISR(ADCvaluesQueueHandle, &glADCbuffer, &xHigherPriorityTaskWoken);

		/* Start next conversion */
		SENSOR_StartADC(&glADCvalues, &hadc1, &hadc2);









	//	/* Private variables */
//	static portBASE_TYPE xHigherPriorityTaskWoken;
//	xHigherPriorityTaskWoken = pdFALSE;
//
//	PROTECTION_State ProtectionState1 = PROTECTION_TRIPPED, ProtectionState2 = PROTECTION_TRIPPED, ProtectionState3 = PROTECTION_TRIPPED, ProtectionState4 = PROTECTION_TRIPPED;
//
//	/* If ADC1 conversion complete */
//	if (hadc->Instance == ADC1)
//	{
//		/* Stop ADC */
//		SENSOR_StopADC(&hadc1, &hadc2);
//
//		/* Calculate instantaneous currents */
//		SENSOR_CalculateInstCurrents(&glADCvalues, &glCurrents);
//
//		/* Perform over current protection function for phase L1 and L3 */
//		ProtectionState1 = PROTECTION_OverCurrent(glCurrents.currIL1, glUpperThrdIL1);
//		ProtectionState2 = PROTECTION_OverCurrent(glCurrents.currIL3, glUpperThrdIL3);
//
//		/* If protection tripped */
//		if ((ProtectionState1 == PROTECTION_TRIPPED) || (ProtectionState2 == PROTECTION_TRIPPED))
//		{
//			/* Stop PWM and give semaphore */
//			MOTOR_StopPWM(&htim1);
//			xSemaphoreGiveFromISR(PhaseOverCurrentSemHandle, &xHigherPriorityTaskWoken);
//		}
//		else
//		{
//			/* Perform current rise protection function for phase L1 and L3 */
//			ProtectionState3 = PROTECTION_CurrentRise(glCurrents.currIL1, glCurrents.prevIL1, PROT_CONF_CURRENT_RISE_LIMIT);
//			ProtectionState4 = PROTECTION_CurrentRise(glCurrents.currIL3, glCurrents.prevIL3, PROT_CONF_CURRENT_RISE_LIMIT);
//
//			/* If protection tripped */
//			if ((ProtectionState3 == PROTECTION_TRIPPED) || (ProtectionState4 == PROTECTION_TRIPPED))
//			{
//				/* Stop PWM and give semaphore */
//				MOTOR_StopPWM(&htim1);
//				xSemaphoreGiveFromISR(PhaseCurrentRiseSemHandle, &xHigherPriorityTaskWoken);
//			}
//			else
//			{
//				/* Shift instantaneous currents buffer */
//				for (uint16_t i = 0; i < (SENSOR_INST_CURR_BUFFER_SIZE - 1); i ++)
//				{
//					glInstCurrents.bufferIL1[i] = glInstCurrents.bufferIL1[i + 1];
//					glInstCurrents.bufferIL3[i] = glInstCurrents.bufferIL3[i + 1];
//				}
//
//				/* Fill in last buffers element */
//				glInstCurrents.Status = glCurrents.Status;
//				glInstCurrents.bufferIL1[SENSOR_INST_CURR_BUFFER_SIZE - 1] = glCurrents.currIL1;
//				glInstCurrents.bufferIL3[SENSOR_INST_CURR_BUFFER_SIZE - 1] = glCurrents.currIL3;
//
//				/* If currents sending time has elapsed */
//				if (glCurrentsSendingCnt >= glCurrentsSendingPeriod)
//				{
//					/* Send instantaneous currents to the queue */
//					xQueueOverwriteFromISR(CurrentsQueueHandle, &glInstCurrents, &xHigherPriorityTaskWoken);
//
//					glCurrentsSendingCnt = 0;
//				}
//				else glCurrentsSendingCnt ++;
//			}
//		}
//	}
























	}

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
