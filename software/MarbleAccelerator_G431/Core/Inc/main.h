/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"
#include "stm32g4xx_ll_adc.h"
#include "stm32g4xx_ll_opamp.h"
#include "stm32g4xx_ll_rcc.h"
#include "stm32g4xx_ll_bus.h"
#include "stm32g4xx_ll_crs.h"
#include "stm32g4xx_ll_system.h"
#include "stm32g4xx_ll_exti.h"
#include "stm32g4xx_ll_cortex.h"
#include "stm32g4xx_ll_utils.h"
#include "stm32g4xx_ll_pwr.h"
#include "stm32g4xx_ll_dma.h"
#include "stm32g4xx_ll_tim.h"
#include "stm32g4xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWM_1N_Pin LL_GPIO_PIN_13
#define PWM_1N_GPIO_Port GPIOC
#define CAN_TERM_Pin LL_GPIO_PIN_14
#define CAN_TERM_GPIO_Port GPIOC
#define VBUS_Pin LL_GPIO_PIN_0
#define VBUS_GPIO_Port GPIOA
#define POTI_Pin LL_GPIO_PIN_12
#define POTI_GPIO_Port GPIOB
#define TEMP_Pin LL_GPIO_PIN_14
#define TEMP_GPIO_Port GPIOB
#define PWM_3N_Pin LL_GPIO_PIN_15
#define PWM_3N_GPIO_Port GPIOB
#define LED_Pin LL_GPIO_PIN_6
#define LED_GPIO_Port GPIOC
#define PWM_1_Pin LL_GPIO_PIN_8
#define PWM_1_GPIO_Port GPIOA
#define PWM_2_Pin LL_GPIO_PIN_9
#define PWM_2_GPIO_Port GPIOA
#define PWM_3_Pin LL_GPIO_PIN_10
#define PWM_3_GPIO_Port GPIOA
#define CAN_RX_Pin LL_GPIO_PIN_11
#define CAN_RX_GPIO_Port GPIOA
#define PWM_2N_Pin LL_GPIO_PIN_12
#define PWM_2N_GPIO_Port GPIOA
#define J3_PWM_Pin LL_GPIO_PIN_15
#define J3_PWM_GPIO_Port GPIOA
#define BUTTON_Pin LL_GPIO_PIN_10
#define BUTTON_GPIO_Port GPIOC
#define CAN_SHDN_Pin LL_GPIO_PIN_11
#define CAN_SHDN_GPIO_Port GPIOC
#define ENC_A_Pin LL_GPIO_PIN_6
#define ENC_A_GPIO_Port GPIOB
#define ENC_B_Pin LL_GPIO_PIN_7
#define ENC_B_GPIO_Port GPIOB
#define ENC_Z_Pin LL_GPIO_PIN_8
#define ENC_Z_GPIO_Port GPIOB
#define CAN_TX_Pin LL_GPIO_PIN_9
#define CAN_TX_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
