/**
  ******************************************************************************
  * @file    platform_config.h
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    29-June-2012
  * @brief   Evaluation board specific configuration file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H
/* Macros ------------------------------------------------------------------*/

/* Uncomment the mecro below if you build binary for DFU*/
//#define USE_DFU

/* Uncomment the mecro below if you want to stop just after COM port configuration */
//#define STOP_AT_STARTUP

/* Uncomment the line corresponding to the STMicroelectronics evaluation board
   used to run the example */
#if !defined (USE_STM3210B_EVAL) &&  !defined (USE_STM3210E_EVAL)  &&  !defined (USE_STM3210C_EVAL)  &&  !defined (USE_STM32L152_EVAL) &&  !defined (USE_STM32L152D_EVAL) &&  \
	!defined (USE_STM32_P103) && \
	!defined (USE_STM32_H103) && \
	!defined (USE_CQ_STARM) && \
	!defined (USE_CQ_ST103Z) && \
	!defined (USE_STM3210E_EVAL) && \
	!defined (USE_STBEE) && \
	!defined (USE_STBEE_MINI) && \
	!defined (USE_STBEE_MINI_SWD) && \
	!defined (USE_STM32_VLD)

//	#define USE_STM32_P103
//	#define USE_STM32_H103
//	#define USE_CQ_STARM
//	#define USE_CQ_ST103Z
//	#define USE_STM3210E_EVAL
	#define USE_STBEE
//	#define USE_STBEE_MINI
//	#define USE_STBEE_MINI_SWD
//	#define USE_STM32_VLD

//	#define USE_STM3210B_EVAL
//	#define USE_STM3210E_EVAL
//	#define USE_STM3210C_EVAL
//	#define USE_STM32L152_EVAL
//	#define USE_STM32L152D_EVAL

#endif

/* Includes ------------------------------------------------------------------*/
#if defined(STM32L1XX_MD) || defined(STM32L1XX_HD)|| defined(STM32L1XX_MD_PLUS)
 #include "stm32l1xx.h"

 #if defined (USE_STM32L152_EVAL)
  #include "stm32l152_eval.h"
 #elif defined (USE_STM32L152D_EVAL)
  #include "stm32l152d_eval.h"
 #else
  #error "Missing define: USE_STM32L152_EVAL or USE_STM32L152D_EVAL"
 #endif /* USE_STM32L152_EVAL */
#elif defined (STM32F10X_MD) || defined (STM32F10X_HD) || defined (STM32F10X_XL) || defined (STM32F10X_CL)
 #include "stm32f10x.h"
 #include "spi_if.h"
 #include "nor_if.h"
 #include "fsmc_nor.h"

 #if defined (USE_STM3210B_EVAL)
  #include "stm3210b_eval.h"
  #include "stm3210b_eval_spi_flash.h"
 #elif defined (USE_STM3210E_EVAL)
  #include "stm3210e_eval.h"
  #include "stm3210e_eval_spi_flash.h"
 #elif defined (USE_STM3210C_EVAL)
  #include "stm3210c_eval.h"
  #include "stm3210c_eval_ioe.h"
  #include "stm3210c_eval_spi_sd.h"

 #elif defined (USE_STM32_P103)
  #include "STM32_P103.h"
 #elif defined (USE_STM32_H103)
  #include "STM32_H103.h"
 #elif defined (USE_CQ_STARM)
  #include "CQ_STARM.h"
 #elif defined (USE_CQ_ST103Z)
  #include "CQ_ST103Z.h"
 #elif defined (USE_STM3210E_EVAL)
  #include "STM3210E_EVAL.h"
 #elif defined (USE_STBEE)
  #include "STBee.h"
 #elif defined (USE_STBEE_MINI)
  #include "STBee_Mini.h"
 #elif defined (USE_STBEE_MINI_SWD)
  #include "STBee_Mini_SWD.h"
 #elif defined (USE_STM32_VLD)
  #include "STM32_VLD.h"

 #else
  #error "Missing define: USE_STM3210B_EVAL, USE_STM3210E_EVAL or USE_STM3210C_EVAL"
 #endif /* USE_STM3210B_EVAL */
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Uncomment the mecro below interface you to use as cprintf() macro*/
#if !defined (USE_USART1) && \
    !defined (USE_USART2) && \
    !defined (USE_USART3) && \
    !defined (USE_DCC) && \
    !defined (USE_VCP)

#define USE_USART1
//#define USE_USART2
//#define USE_USART3
//#define USE_DCC
//#define USE_VCP

#endif

//Define cprintf of actual interface function
#ifdef USE_USART1
  #warning "USE_USART1 defined at platform_config.h"
#define  USARTX_Configuration()          USART_Configuration(USART1, 115200)
#define  RECEIVE_DATA                    USART_ReceiveData(USART1)
#define  cputchar(arg)                   USART_PrintChar(USART1, arg)
#define  cprintf(...)                    USART_PrintFormatted(USART1, __VA_ARGS__)
#define  RX_BUFFER_IS_NOT_EMPTY          USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET
#define  RX_BUFFER_IS_EMPTY              USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET
#define  TX_BUFFER_IS_NOT_EMPTY          USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET
#elif defined USE_USART2
#define  USARTX_Configuration()          USART_Configuration(USART2, 115200)
#define  RECEIVE_DATA                    USART_ReceiveData(USART2)
#define  cputchar(arg)                   USART_PrintChar(USART2, arg)
#define  cprintf(...)                    USART_PrintFormatted(USART2, __VA_ARGS__)
#define  RX_BUFFER_IS_NOT_EMPTY          USART_GetFlagStatus(USART2, USART_FLAG_RXNE) != RESET
#define  RX_BUFFER_IS_EMPTY              USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET
#define  TX_BUFFER_IS_NOT_EMPTY          USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET
#elif defined USE_USART3
#define  USARTX_Configuration()          USART_Configuration(USART3, 115200)
#define  RECEIVE_DATA                    USART_ReceiveData(USART3)
#define  cputchar(arg)                   USART_PrintChar(USART3, arg)
#define  cprintf(...)                    USART_PrintFormatted(USART3, __VA_ARGS__)
#define  RX_BUFFER_IS_NOT_EMPTY          USART_GetFlagStatus(USART3, USART_FLAG_RXNE) != RESET
#define  RX_BUFFER_IS_EMPTY              USART_GetFlagStatus(USART3, USART_FLAG_RXNE) == RESET
#define  TX_BUFFER_IS_NOT_EMPTY          USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET
#elif defined USE_DCC
#define  USARTX_Configuration()          (0)
#define  RECEIVE_DATA                    (0)
#define  cputchar(arg)                   DCC_PrintChar(arg)
#define  cprintf(...)                    DCC_PrintFormatted(__VA_ARGS__)
#define  RX_BUFFER_IS_NOT_EMPTY          (0)
#define  RX_BUFFER_IS_EMPTY              (0)
#define  TX_BUFFER_IS_NOT_EMPTY          (0)
#elif defined USE_VCP
#define  USARTX_Configuration()          {}
#define  RECEIVE_DATA                    VCP_ReceiveData()
#define  cputchar(arg)                   VCP_PrintChar(arg)
#define  cprintf(...)                    VCP_PrintFormatted(__VA_ARGS__)
#define  RX_BUFFER_IS_NOT_EMPTY          (count_out != 0) && (bDeviceState == CONFIGURED)
#define  RX_BUFFER_IS_EMPTY              (count_out == 0) && (bDeviceState == CONFIGURED)
#define  TX_BUFFER_IS_NOT_EMPTY          RESET
#else
//#error "USE_USART1 or the other STDIO device is Not defined! at platform_config.h"
#endif

//Define the location of vector table
#ifdef USE_DFU
#define  VECTOR_OFFSET                  0x3000
#else
#define  VECTOR_OFFSET                  0x0
#endif

/* Define the STM32F10x hardware depending on the used evaluation board */
#ifdef USE_STM3210B_EVAL
  #define USB_DISCONNECT                      GPIOD  
  #define USB_DISCONNECT_PIN                  GPIO_Pin_9
  #define RCC_APB2Periph_GPIO_DISCONNECT      RCC_APB2Periph_GPIOD

#elif defined (USE_STM3210E_EVAL)
  #define USB_DISCONNECT                      GPIOB  
  #define USB_DISCONNECT_PIN                  GPIO_Pin_14
  #define RCC_APB2Periph_GPIO_DISCONNECT      RCC_APB2Periph_GPIOB

#elif defined (USE_STM3210C_EVAL)
  #define USB_DISCONNECT                      0  
  #define USB_DISCONNECT_PIN                  0
  #define RCC_APB2Periph_GPIO_DISCONNECT      0

#elif defined (USE_STM32L152_EVAL) || defined (USE_STM32L152D_EVAL)
 /* 
   For STM32L15xx devices it is possible to use the internal USB pullup
   controlled by register SYSCFG_PMC (refer to RM0038 reference manual for
   more details).
   It is also possible to use external pullup (and disable the internal pullup)
   by setting the define USB_USE_EXTERNAL_PULLUP in file platform_config.h
   and configuring the right pin to be used for the external pull up configuration.
   To have more details on how to use an external pull up, please refer to 
   STM3210E-EVAL evaluation board manuals.
   */
 /* Uncomment the following define to use an external pull up instead of the 
    integrated STM32L15xx internal pull up. In this case make sure to set up
    correctly the external required hardware and the GPIO defines below.*/
/* #define USB_USE_EXTERNAL_PULLUP */

 #if !defined(USB_USE_EXTERNAL_PULLUP)
  #define STM32L15_USB_CONNECT                SYSCFG_USBPuCmd(ENABLE)
  #define STM32L15_USB_DISCONNECT             SYSCFG_USBPuCmd(DISABLE)

 #elif defined(USB_USE_EXTERNAL_PULLUP)
  /* PA0 is chosen just as illustrating example, you should modify the defines
    below according to your hardware configuration. */ 
  #define USB_DISCONNECT                      GPIOA
  #define USB_DISCONNECT_PIN                  GPIO_Pin_0
  #define RCC_AHBPeriph_GPIO_DISCONNECT       RCC_AHBPeriph_GPIOA
  #define STM32L15_USB_CONNECT                GPIO_ResetBits(USB_DISCONNECT, USB_DISCONNECT_PIN)
  #define STM32L15_USB_DISCONNECT             GPIO_SetBits(USB_DISCONNECT, USB_DISCONNECT_PIN)
 #endif /* USB_USE_EXTERNAL_PULLUP */


#endif /* USE_STM3210B_EVAL */
/* Uncomment the line corresponding to the STMicroelectronics evaluation board
   used to run the example */
#if !defined (JTAG_SWD_Enabled) && \
    !defined (JTAG_SWD_Enabled_without_NJTRST) && \
    !defined (JTAG_Disabled_SWD_Enabled) && \
    !defined (JTAG_SWD_Disabled)

#define JTAG_SWD_Enabled
//#define JTAG_SWD_Enabled_without_NJTRST
//#define JTAG_Disabled_SWD_Enabled
//#define JTAG_SWD_Disabled

#endif

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/* Private function prototypes -----------------------------------------------*/
void BoardInit(void);


#endif /* __PLATFORM_CONFIG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
