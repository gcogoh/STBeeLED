/**
  ******************************************************************************
  * @file    lib/Platform/STM32_VLD.h
  * @author  Yasuo Kawachi
  * @version  V1.0.0
  * @date  04/15/2009
  * @brief  Evaluation board specific configuration file.
  ******************************************************************************
  * @copy
  *
  * Copyright 2008-2009 Yasuo Kawachi All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions are met:
  *  1. Redistributions of source code must retain the above copyright notice,
  *  this list of conditions and the following disclaimer.
  *  2. Redistributions in binary form must reproduce the above copyright notice,
  *  this list of conditions and the following disclaimer in the documentation
  *  and/or other materials provided with the distribution.
  *
  * THIS SOFTWARE IS PROVIDED BY YASUO KAWACHI "AS IS" AND ANY EXPRESS OR IMPLIE  D
  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
  * EVENT SHALL YASUO KAWACHI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  * This software way contain the part of STMicroelectronics firmware.
  * Below notice is applied to the part, but the above BSD license is not.
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * COPYRIGHT 2009 STMicroelectronics
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32_VLD_H
#define __STM32_VLD_H
/* Macros ------------------------------------------------------------------*/
#define JTAG_Disabled_SWD_Enabled

#define RCC_APB2Periph_ALLGPIO             (RCC_APB2Periph_GPIOA \
                                          | RCC_APB2Periph_GPIOB \
                                          | RCC_APB2Periph_GPIOC)

#define  GPIOX_PORT                      GPIOB
#define  GPIOX_RCC                       RCC_APB2Periph_GPIOB
#define  GPIOX_0_PIN                     GPIO_Pin_0
#define  GPIOX_1_PIN                     GPIO_Pin_1
#define  GPIOX_2_PIN                     GPIO_Pin_2
#define  GPIOX_3_PIN                     GPIO_Pin_3
#define  GPIOX_4_PIN                     GPIO_Pin_4
#define  GPIOX_5_PIN                     GPIO_Pin_5
#define  GPIOX_6_PIN                     GPIO_Pin_6
#define  GPIOX_7_PIN                     GPIO_Pin_7
//#define  GPIOX_8_PIN                     0
//#define  GPIOX_9_PIN                     0
//#define  GPIOX_10_PIN                    0
//#define  GPIOX_11_PIN                    0
//#define  GPIOX_12_PIN                    0
//#define  GPIOX_13_PIN                    0
//#define  GPIOX_14_PIN                    0
//#define  GPIOX_15_PIN                    0
#define  GPIOX_PORTSOURCE                GPIO_PortSourceGPIOB
#define  GPIOX_0_PINSOURCE               GPIO_PinSource0
#define  GPIOX_1_PINSOURCE               GPIO_PinSource1
#define  GPIOX_2_PINSOURCE               GPIO_PinSource2
#define  GPIOX_3_PINSOURCE               GPIO_PinSource3
#define  GPIOX_4_PINSOURCE               GPIO_PinSource4
#define  GPIOX_5_PINSOURCE               GPIO_PinSource5
#define  GPIOX_6_PINSOURCE               GPIO_PinSource6
#define  GPIOX_7_PINSOURCE               GPIO_PinSource7

#define  GPIOY_0_PORT                     GPIOC
#define  GPIOY_0_RCC                      RCC_APB2Periph_GPIOC
#define  GPIOY_0_PIN                      GPIO_Pin_3
#define  GPIOY_1_PORT                     GPIOC
#define  GPIOY_1_RCC                      RCC_APB2Periph_GPIOC
#define  GPIOY_1_PIN                      GPIO_Pin_4
#define  GPIOY_2_PORT                     GPIOC
#define  GPIOY_2_RCC                      RCC_APB2Periph_GPIOC
#define  GPIOY_2_PIN                      GPIO_Pin_5
#define  GPIOY_3_PORT                     GPIOC
#define  GPIOY_3_RCC                      RCC_APB2Periph_GPIOC
#define  GPIOY_3_PIN                      GPIO_Pin_10
#define  GPIOY_4_PORT                     GPIOC
#define  GPIOY_4_RCC                      RCC_APB2Periph_GPIOC
#define  GPIOY_4_PIN                      GPIO_Pin_11
#define  GPIOY_5_PORT                     GPIOC
#define  GPIOY_5_RCC                      RCC_APB2Periph_GPIOC
#define  GPIOY_5_PIN                      GPIO_Pin_12
#define  GPIOY_6_PORT                     GPIOA
#define  GPIOY_6_RCC                      RCC_APB2Periph_GPIOA
#define  GPIOY_6_PIN                      GPIO_Pin_15
#define  GPIOY_7_PORT                     GPIOB
#define  GPIOY_7_RCC                      RCC_APB2Periph_GPIOB
#define  GPIOY_7_PIN                      GPIO_Pin_15
//#define  GPIOY_8_PORT                     GPIOC
//#define  GPIOY_8_RCC                      RCC_APB2Periph_GPIOC
//#define  GPIOY_8_PIN                      GPIO_Pin_8
//#define  GPIOY_9_PORT                     GPIOC
//#define  GPIOY_9_RCC                      RCC_APB2Periph_GPIOC
//#define  GPIOY_9_PIN                      GPIO_Pin_9
//#define  GPIOY_10_PORT                    0
//#define  GPIOY_10_RCC                     0
//#define  GPIOY_10_PIN                     0
//#define  GPIOY_11_PORT                    0
//#define  GPIOY_11_RCC                     0
//#define  GPIOY_11_PIN                     0
//#define  GPIOY_12_PORT                    0
//#define  GPIOY_12_RCC                     0
//#define  GPIOY_12_PIN                     0
//#define  GPIOY_13_PORT                    0
//#define  GPIOY_13                         0
//#define  GPIOY_13_PIN                     0
//#define  GPIOY_14_PORT                    0
//#define  GPIOY_14_RCC                     0
//#define  GPIOY_14_PIN                     0
//#define  GPIOY_15_PORT                    0
//#define  GPIOY_15_RCC                     0
//#define  GPIOY_15_PIN                     0

#define  TIM1_PORT                       GPIOA
#define  TIM1_RCC                        RCC_APB2Periph_TIM1
#define  TIM1_GPIO_RCC                   RCC_APB2Periph_GPIOA
#define  TIM1_CH1_PIN                    GPIO_Pin_8
#define  TIM1_CH2_PIN                    GPIO_Pin_9
#define  TIM1_CH3_PIN                    GPIO_Pin_10
#define  TIM1_CH4_PIN                    GPIO_Pin_11
#define  TIM1_ETR_PIN                    GPIO_Pin_12
//#define  TIM1_N_PORT                     GPIOB
//#define  TIM1_N_GPIO_RCC                 RCC_APB2Periph_GPIOB
//#define  TIM1_CH1N_PIN                   GPIO_Pin_13
//#define  TIM1_CH2N_PIN                   GPIO_Pin_14
//#define  TIM1_CH3N_PIN                   GPIO_Pin_15
//#define  TIM1_BKIN_PIN                   GPIO_Pin_12
//#define  FULL_REMAP_TIM1

//#define  TIM2_PORT                       0
#define  TIM2_RCC                        RCC_APB1Periph_TIM2
//#define  TIM2_GPIO_RCC                   0
//#define  TIM2_CH1_PIN                    0
//#define  TIM2_CH2_PIN                    0
//#define  TIM2_CH3_PIN                    0
//#define  TIM2_CH4_PIN                    0

#define  TIM3_RCC                        RCC_APB1Periph_TIM3
#define  TIM3_CH12_PORT                  GPIOC
#define  TIM3_CH12_GPIO_RCC              RCC_APB2Periph_GPIOC
#define  TIM3_CH1_PIN                    GPIO_Pin_6
#define  TIM3_CH2_PIN                    GPIO_Pin_7
#define  TIM3_CH34_PORT                  GPIOC
#define  TIM3_CH34_GPIO_RCC              RCC_APB2Periph_GPIOC
#define  TIM3_CH3_PIN                    GPIO_Pin_8
#define  TIM3_CH4_PIN                    GPIO_Pin_9
#define  FULL_REMAP_TIM3

//#define  TIM4_PORT                       GPIOB
#define  TIM4_RCC                        RCC_APB1Periph_TIM4
//#define  TIM4_GPIO_RCC                   RCC_APB2Periph_GPIOB
//#define  TIM4_CH1_PIN                    GPIO_Pin_6
//#define  TIM4_CH2_PIN                    GPIO_Pin_7
//#define  TIM4_CH3_PIN                    GPIO_Pin_8
//#define  TIM4_CH4_PIN                    GPIO_Pin_9

//#define  USART1_PORT                     GPIOB
//#define  USART1_RCC                      RCC_APB2Periph_USART1
//#define  USART1_GPIO_RCC                 RCC_APB2Periph_GPIOB
//#define  USART1_CK_PIN                   0
//#define  USART1_TX_PIN                   GPIO_Pin_6
//#define  USART1_RX_PIN                   GPIO_Pin_7
//#define REMAP_USART1

#define  USART2_PORT                     GPIOA
#define  USART2_RCC                      RCC_APB1Periph_USART2
#define  USART2_GPIO_RCC                 RCC_APB2Periph_GPIOA
#define  USART2_TX_PIN                   GPIO_Pin_2
#define  USART2_RX_PIN                   GPIO_Pin_3
//#define  USART2_CK_PIN                   0
//#define  USART2_RTS_PIN                  0
//#define  USART2_CTS_PIN                  0
//#define REMAP_USART2

#define  USART3_PORT                     GPIOB
#define  USART3_RCC                      RCC_APB1Periph_USART3
#define  USART3_GPIO_RCC                 RCC_APB2Periph_GPIOB
#define  USART3_TX_PIN                   GPIO_Pin_10
#define  USART3_RX_PIN                   GPIO_Pin_11
#define  USART3_CK_PIN                   GPIO_Pin_12
#define  USART3_RTS_PIN                  GPIO_Pin_13
#define  USART3_CTS_PIN                  GPIO_Pin_14
//#define PARTIAL_REMAP_USART3
//#define FULL_REMAP_USART3

#define  I2C1_PORT                       GPIOB
#define  I2C1_RCC                        RCC_APB1Periph_I2C1
#define  I2C1_GPIO_RCC                   RCC_APB2Periph_GPIOB
//#define  I2C1_SMBAI_PIN                  0
#define  I2C1_SCL_PIN                    GPIO_Pin_8
#define  I2C1_SDA_PIN                    GPIO_Pin_9
#define REMAP_I2C1

//#define  I2C2_PORT                       0
//#define  I2C2_RCC                        0
//#define  I2C2_GPIO_RCC                   0
//#define  I2C2_SCL_PIN                    0
//#define  I2C2_SDA_PIN                    0

#define  SPI1_PORT                       GPIOA
#define  SPI1_RCC                        RCC_APB2Periph_SPI1
#define  SPI1_GPIO_RCC                   RCC_APB2Periph_GPIOA
#define  SPI1_NSS_PIN                    GPIO_Pin_4
#define  SPI1_SCK_PIN                    GPIO_Pin_5
#define  SPI1_MISO_PIN                   GPIO_Pin_6
#define  SPI1_MOSI_PIN                   GPIO_Pin_7

//#define  SPI2_PORT                       0
//#define  SPI2_RCC                        0
//#define  SPI2_GPIO_RCC                   0
//#define  SPI2_NSS_PIN                    0
//#define  SPI2_SCK_PIN                    0
//#define  SPI2_MISO_PIN                   0
//#define  SPI2_MOSI_PIN                   0

//Definition for sd_spi_stm32.c / ff.c
#define CARD_SUPPLY_SWITCHABLE   0
#define SOCKET_WP_CP_CONNECTED   0
#define GPIO_WP_CP               GPIOC
#define RCC_APB2Periph_GPIO_WP_CP  RCC_APB2Periph_GPIOC
#define GPIO_Pin_WP              GPIO_Pin_6
#define GPIO_Pin_CP              GPIO_Pin_7
#define GPIO_Mode_WP_CP          GPIO_Mode_IN_FLOATING
#define SPI_SD                   SPI2
#define GPIO_CS                  GPIOB
#define RCC_APB2Periph_GPIO_CS   RCC_APB2Periph_GPIOB
#define GPIO_Pin_CS              GPIO_Pin_12
#define DMA_Channel_SPI_SD_RX    DMA1_Channel4
#define DMA_Channel_SPI_SD_TX    DMA1_Channel5
#define DMA_FLAG_SPI_SD_TC_RX    DMA1_FLAG_TC4
#define DMA_FLAG_SPI_SD_TC_TX    DMA1_FLAG_TC5
#define GPIO_SPI_SD              GPIOB
#define GPIO_Pin_SPI_SD_SCK      GPIO_Pin_13
#define GPIO_Pin_SPI_SD_MISO     GPIO_Pin_14
#define GPIO_Pin_SPI_SD_MOSI     GPIO_Pin_15
#define RCC_APBPeriphClockCmd_SPI_SD  RCC_APB1PeriphClockCmd
#define RCC_APBPeriph_SPI_SD     RCC_APB1Periph_SPI2
#define SPI_BaudRatePrescaler_SPI_SD  SPI_BaudRatePrescaler_4
#define STM32_USE_DMA

//#define  CAN1_PORT                       GPIOB
//#define  CAN1_RCC                        RCC_APB1Periph_CAN1
//#define  CAN1_GPIO_RCC                   RCC_APB2Periph_GPIOB
//#define  CAN1RX_PIN                      GPIO_Pin_8
//#define  CAN1TX_PIN                      GPIO_Pin_9

#define  ADC123_IN1_CH                   ADC_Channel_1
#define  ADC123_IN1_PORT                 GPIOA
#define  ADC123_IN1_PIN                  GPIO_Pin_1
#define  ADC12_IN8_CH                    ADC_Channel_8
#define  ADC12_IN8_PORT                  GPIOB
#define  ADC12_IN8_PIN                   GPIO_Pin_0
#define  ADC12_IN9_CH                    ADC_Channel_9
#define  ADC12_IN9_PORT                  GPIOB
#define  ADC12_IN9_PIN                   GPIO_Pin_1
#define  ADC123_IN10_CH                  ADC_Channel_10
#define  ADC123_IN10_PORT                GPIOC
#define  ADC123_IN10_PIN                 GPIO_Pin_0
#define  ADC123_IN11_CH                  ADC_Channel_11
#define  ADC123_IN11_PORT                GPIOC
#define  ADC123_IN11_PIN                 GPIO_Pin_1
#define  ADC123_IN12_CH                  ADC_Channel_12
#define  ADC123_IN12_PORT                GPIOC
#define  ADC123_IN12_PIN                 GPIO_Pin_2
#define  ADC_IN0_3_GPIO_RCC              RCC_APB2Periph_GPIOA
#define  ADC_IN4_7_GPIO_RCC              RCC_APB2Periph_GPIOF
#define  ADC_IN8_9_GPIO_RCC              RCC_APB2Periph_GPIOB
#define  ADC_IN10_15_GPIO_RCC            RCC_APB2Periph_GPIOC

#define  OB_SW_PORT                      GPIOA
#define  OB_SW_GPIO_RCC                  RCC_APB2Periph_GPIOA
#define  OB_SW_PIN                       GPIO_Pin_0
#define  OB_SW_PORTSOURCE                GPIO_PortSourceGPIOA
#define  OB_SW_PINSOURCE                 GPIO_PinSource0
#define  OB_SW_IS_PRESSED                GPIO_ReadInputDataBit(OB_SW_PORT, OB_SW_PIN) != 0
#define  OB_SW_EXTI_LINE                 EXTI_Line0
#define  OB_SW_EXTI_IRQn                 EXTI0_IRQn
#define  OB_SW_EXTI_NUM                  0

#define  OB_LED_PORT                     GPIOC
#define  OB_LED_GPIO_RCC                 RCC_APB2Periph_GPIOC
#define  OB_LED_PIN                      GPIO_Pin_9

//#define  USB_DISCONNECT                  GPIOC
//#define  USB_DISCONNECT_PIN              GPIO_Pin_11
//#define  RCC_APB2Periph_GPIO_DISCONNECT  RCC_APB2Periph_GPIOC

#endif /* __STM32_VLD_H */
