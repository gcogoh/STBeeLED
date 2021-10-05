/**
 ******************************************************************************
 * @file    main.c
 * @author  MCD Application Team
 * @version V3.4.0
 * @date    29-June-2012
 * @brief   Device Firmware Upgrade(DFU) demo main file
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "platform_config.h"
#include "com_config.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void GPIO_Configuration(void);
void Delay(__IO uint32_t nCount);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program.
 * @param  None
 * @retval : None
 */
int main(void)
{

	// Configure board specific setting
	BoardInit();
	// Setting up COM port for Print function
	COM_Configuration();
	GPIO_Configuration();

	cprintf("Hello Led Dimming Sample (5)!\r\n");
	cprintf("On-board LED lighting up and out gradually.\r\n");
	cprintf("Report when start lighting up and out via serial port.\r\n");
	__IO int32_t i, j, on_time, off_time;

	while (1)
	{
		cprintf("Lighting down v\r\n");

		for (i = 0; i < 100; i++)
		{
			for (j = 0; j <= 5; j++)
			{

				on_time = 1000 - (i * 10);
				off_time = i * 20;

				/* Turn on GPIOX_0 */
				GPIO_SetBits(OB_LED_PORT, OB_LED_PIN);
				/* Insert delay */
				Delay(off_time);

				/* Turn off GPIOX_0 */
				GPIO_ResetBits(OB_LED_PORT, OB_LED_PIN);
				/* Insert delay */
				Delay(on_time);
			}
		}

		// Keep LED turn off while cprintf sending message
		GPIO_SetBits(OB_LED_PORT, OB_LED_PIN);

		cprintf("Lighting up   ^\r\n");

		for (i = 100; i > 0; i--)
		{
			for (j = 0; j <= 5; j++)
			{

				on_time = 1000 - (i * 10);
				off_time = i * 20;

				/* Turn on GPIOX_0 */
				GPIO_SetBits(OB_LED_PORT, OB_LED_PIN);
				/* Insert delay */
				Delay(off_time);

				/* Turn off GPIOX_0 */
				GPIO_ResetBits(OB_LED_PORT, OB_LED_PIN);
				/* Insert delay */
				Delay(on_time);
			}
		}
	}
}

/**
 * @brief  Configure the GPIO Pins.
 * @param  None
 * @retval : None
 */
void GPIO_Configuration(void)
{

	//Supply APB2 Clock
	RCC_APB2PeriphClockCmd(OB_LED_GPIO_RCC, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIO Configuration: output push-pull */
	GPIO_InitStructure.GPIO_Pin = OB_LED_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(OB_LED_PORT, &GPIO_InitStructure);
}

/**
 * @brief  Inserts a delay time.
 * @param nCount: specifies the delay time length.
 * @retval : None
 */
void Delay(__IO uint32_t nCount)
{
	for (; nCount != 0; nCount--)
		;
}
