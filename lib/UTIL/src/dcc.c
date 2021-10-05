/**
  ******************************************************************************
  * @file    UTIL/src/dcc.c
  * @author  Yasuo Kawachi
  * @version  V1.0.0
  * @date  04/15/2009
  * @brief  DCC utility functions
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

/* Includes ------------------------------------------------------------------*/
#include "dcc.h"
#include "toascii.h"
#include <stdarg.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TARGET_REQ_DEBUGCHAR                            0x02
#define NVIC_DBG_DATA_R         (*((volatile unsigned short *)0xE000EDF8))

#define BUSY    1
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  send a byte data
  * @param  charvalue : byte data to be used
  * @retval None
  */
void DCC_PrintChar(int8_t charvalue)
{

  uint16_t charvalue16;
  charvalue16 = (uint16_t)charvalue;

  while (NVIC_DBG_DATA_R & BUSY);
  NVIC_DBG_DATA_R = (uint16_t)((TARGET_REQ_DEBUGCHAR << 8) | BUSY);

  while (NVIC_DBG_DATA_R & BUSY);
  NVIC_DBG_DATA_R = (uint16_t)(BUSY);

  while (NVIC_DBG_DATA_R & BUSY);
  NVIC_DBG_DATA_R = (uint16_t)((charvalue16 << 8) | BUSY);

  while (NVIC_DBG_DATA_R & BUSY);
  NVIC_DBG_DATA_R = (uint16_t)(BUSY);


}

/**
  * @brief  send string
  * @param  string : pointer to stirng
  * @retval None
  */
void DCC_PrintString(const int8_t* string)
{
  while(*string != '\0')
    {
      DCC_PrintChar(*string);
      string++;
    }
}

/**
  * @brief  Send decimal value by strings via DCC
  * @param  intvalue : integral value to be send
  * @param  width: width to restrict output string
  * @param  plussign : set to print '+' for plus value
  * @retval : None
  */
void DCC_PrintDecimal(int32_t intvalue, uint32_t width, uint8_t plussign)
{
  int8_t buffer[12];
  if (width == 0 && intvalue > 0 && plussign == 0)
    {
      Uint32_tToDecimal(intvalue, &buffer[0], width, ' ');
    }
  else if (width == 0 && intvalue > 0 && plussign == 1)
    {
      buffer[0] = '+';
      Uint32_tToDecimal(intvalue, &buffer[1], width, ' ');
    }
  else if (width == 0 && intvalue < 0)
    {
      buffer[0] = '-';
      Uint32_tToDecimal(-intvalue, &buffer[1], width, ' ');
    }
  else if (width == 0 && intvalue == 0)
    {
      Uint32_tToDecimal(intvalue, &buffer[0], width, ' ');
    }
  else if (plussign != 0 && intvalue > 0)
    {
      buffer[0] = '+';
      Uint32_tToDecimal(intvalue, &buffer[1], width, ' ');
    }
  else if ((plussign == 0 && intvalue > 0) || intvalue == 0)
    {
      buffer[0] = ' ';
      Uint32_tToDecimal(intvalue, &buffer[1], width, ' ');
    }
  else
    {
      buffer[0] = '-';
      Uint32_tToDecimal(-intvalue, &buffer[1], width, ' ');
    }
  DCC_PrintString(buffer);
}

/**
  * @brief  Send decimal value by strings via DCC
  * @param  intvalue : integral value to be send
  * @param  width: width to restrict output string
  * @param  plussign : set to print '+' for plus value
  * @retval : None
  */
void DCC_PrintUnsignedDecimal(int32_t intvalue, uint32_t width)
{
  int8_t buffer[11];

  Uint32_tToDecimal(intvalue, &buffer[0], width, ' ');

  DCC_PrintString(buffer);
}


/**
  * @brief  Send Hexadecimal strings via DCC
  * @param  intvalue : integral value to be send
  * @param  width: width to restrict output string
  * @param  smallcase: 1 to small(90abc), 0 to large(09ABC)
  * @retval : None
  */
void DCC_PrintHexaecimal(int32_t intvalue, uint32_t width, uint8_t smallcase)
{
  int8_t buffer[9];

  Uint32_tToHexadecimal(intvalue, buffer, width, smallcase);

  DCC_PrintString(buffer);
}

/**
  * @brief  Send binary strings via DCC
  * @param  intvalue : integral value to be send
  * @param  width: width to restrict output string
  * @retval : None
  */
void DCC_PrintBinary(int32_t intvalue, uint32_t width)
{
  int8_t buffer[33];

  Uint32_tToBinary(intvalue, buffer, width);

  DCC_PrintString(buffer);
}

/**
  * @brief  Send formatted string via USART
  * @param  string : string to be send
  * @param  ...: set arguments for identifier in string
  * @retval : None
  */
void DCC_PrintFormatted(const int8_t* string, ...)
{
  va_list arg;
  uint8_t width;

  va_start(arg, string);

  while (*string != '\0')
    {
      if(*string == '%')
        {
          width = 0;
          string++;

          // acquire width as long as number lasts
          while (*string >= '0' && *string <= '9')
            {
              width = (width * 10) + (*string - '0');
              string++;
            }

          // detect identifier
          switch(*string)
          {
            // signed decimal without plus sign for plus value
            case 'd':
              DCC_PrintDecimal(va_arg(arg, int32_t) , width, 0);
              string++;
              break;
            // signed decimal with plus sign for plus value
            case 'D':
              DCC_PrintDecimal(va_arg(arg, int32_t) , width, 1);
              string++;
              break;
            // unsigned decimal
            case 'u':
              DCC_PrintUnsignedDecimal(va_arg(arg, int32_t) , width);
              string++;
              break;
            // hexadecimal with small case
            case 'x':
              DCC_PrintHexaecimal(va_arg(arg, uint32_t) , width, 1);
              string++;
              break;
            // hexadecimal with large case
            case 'X':
              DCC_PrintHexaecimal(va_arg(arg, uint32_t) , width, 0);
              string++;
              break;
            // binary
            case 'b':
              DCC_PrintBinary(va_arg(arg, uint32_t) , width);
              string++;
              break;
            // one character
            case 'c':
              DCC_PrintChar((int8_t)va_arg(arg, int32_t));
              string++;
              break;
            // string
            case 's':
              DCC_PrintString(va_arg(arg, int8_t*));
              string++;
              break;
            default:
              DCC_PrintChar(*string);
              string++;
              break;
          }
        }
      else
        {
          DCC_PrintChar(*string);
          string++;
        }
    }

  va_end(arg);
}

