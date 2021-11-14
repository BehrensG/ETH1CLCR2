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
#include "stm32h7xx_hal.h"

#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_cortex.h"
#include "stm32h7xx_ll_system.h"
#include "stm32h7xx_ll_utils.h"
#include "stm32h7xx_ll_pwr.h"
#include "stm32h7xx_ll_gpio.h"
#include "stm32h7xx_ll_dma.h"

#include "stm32h7xx_ll_exti.h"

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
#define IDIFF0_Pin GPIO_PIN_3
#define IDIFF0_GPIO_Port GPIOE
#define SPI4_NSS_Pin GPIO_PIN_4
#define SPI4_NSS_GPIO_Port GPIOE
#define IDIFF1_Pin GPIO_PIN_13
#define IDIFF1_GPIO_Port GPIOC
#define SPI5_NSS_Pin GPIO_PIN_6
#define SPI5_NSS_GPIO_Port GPIOF
#define nRDC_Pin GPIO_PIN_10
#define nRDC_GPIO_Port GPIOF
#define TRIG_EN_Pin GPIO_PIN_9
#define TRIG_EN_GPIO_Port GPIOE
#define TRIG_OUT_Pin GPIO_PIN_10
#define TRIG_OUT_GPIO_Port GPIOE
#define TRIG_IN_Pin GPIO_PIN_11
#define TRIG_IN_GPIO_Port GPIOE
#define CXN_REL6_Pin GPIO_PIN_12
#define CXN_REL6_GPIO_Port GPIOE
#define CXN_REL5_Pin GPIO_PIN_13
#define CXN_REL5_GPIO_Port GPIOE
#define CXN_REL4_Pin GPIO_PIN_14
#define CXN_REL4_GPIO_Port GPIOE
#define CXN_REL3_Pin GPIO_PIN_15
#define CXN_REL3_GPIO_Port GPIOE
#define CXN_REL2_Pin GPIO_PIN_10
#define CXN_REL2_GPIO_Port GPIOB
#define CXN_REL1_Pin GPIO_PIN_11
#define CXN_REL1_GPIO_Port GPIOB
#define SPI2_NSS_Pin GPIO_PIN_12
#define SPI2_NSS_GPIO_Port GPIOB
#define nADC2_RST_Pin GPIO_PIN_15
#define nADC2_RST_GPIO_Port GPIOB
#define ADC2_MDIV_Pin GPIO_PIN_8
#define ADC2_MDIV_GPIO_Port GPIOD
#define nADC2_HPF_Pin GPIO_PIN_9
#define nADC2_HPF_GPIO_Port GPIOD
#define ADC2_M0_Pin GPIO_PIN_10
#define ADC2_M0_GPIO_Port GPIOD
#define EEPROM_WP_Pin GPIO_PIN_11
#define EEPROM_WP_GPIO_Port GPIOD
#define ADC2_M1_Pin GPIO_PIN_14
#define ADC2_M1_GPIO_Port GPIOD
#define IRR0_Pin GPIO_PIN_8
#define IRR0_GPIO_Port GPIOG
#define VDIFF0_Pin GPIO_PIN_6
#define VDIFF0_GPIO_Port GPIOC
#define VDIFF2_Pin GPIO_PIN_7
#define VDIFF2_GPIO_Port GPIOC
#define VDIFF1_Pin GPIO_PIN_8
#define VDIFF1_GPIO_Port GPIOC
#define IRR4_Pin GPIO_PIN_9
#define IRR4_GPIO_Port GPIOA
#define IRR2_Pin GPIO_PIN_10
#define IRR2_GPIO_Port GPIOA
#define IRR1_Pin GPIO_PIN_11
#define IRR1_GPIO_Port GPIOA
#define IRR3_Pin GPIO_PIN_12
#define IRR3_GPIO_Port GPIOA
#define SPI3_NSS_Pin GPIO_PIN_15
#define SPI3_NSS_GPIO_Port GPIOA
#define ADC1_RVS1_Pin GPIO_PIN_0
#define ADC1_RVS1_GPIO_Port GPIOD
#define ADC1_RVS2_Pin GPIO_PIN_1
#define ADC1_RVS2_GPIO_Port GPIOD
#define MCU_DEFAULT_Pin GPIO_PIN_2
#define MCU_DEFAULT_GPIO_Port GPIOD
#define ADC_SEL_Pin GPIO_PIN_3
#define ADC_SEL_GPIO_Port GPIOD
#define LED_BLUE_Pin GPIO_PIN_7
#define LED_BLUE_GPIO_Port GPIOD
#define LED_RED_Pin GPIO_PIN_9
#define LED_RED_GPIO_Port GPIOG
#define LED_GREEN_Pin GPIO_PIN_10
#define LED_GREEN_GPIO_Port GPIOG
#define DDS_LPF_Pin GPIO_PIN_5
#define DDS_LPF_GPIO_Port GPIOB
#define MUX_A0_Pin GPIO_PIN_6
#define MUX_A0_GPIO_Port GPIOB
#define MUX_A1_Pin GPIO_PIN_7
#define MUX_A1_GPIO_Port GPIOB
#define DDS_DIV8_Pin GPIO_PIN_8
#define DDS_DIV8_GPIO_Port GPIOB
#define DDS_DIV4_Pin GPIO_PIN_9
#define DDS_DIV4_GPIO_Port GPIOB
#define DDS_DIV2_Pin GPIO_PIN_0
#define DDS_DIV2_GPIO_Port GPIOE
#define nDDS_DIV10_Pin GPIO_PIN_1
#define nDDS_DIV10_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
