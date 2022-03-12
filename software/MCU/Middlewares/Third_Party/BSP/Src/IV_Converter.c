/*
 * IV_Converter.c
 *
 *  Created on: Mar 12, 2022
 *      Author: grzegorz
 */

#include "IV_Converter.h"

void IV_Converter(uint8_t resistor)
{
	switch(resistor)
	{
		case R1:
		{
			LL_GPIO_SetOutputPin(IRR1_GPIO_Port, IRR1_Pin);
			LL_GPIO_SetOutputPin(IRR2_GPIO_Port, IRR2_Pin);
			LL_GPIO_SetOutputPin(IRR3_GPIO_Port, IRR3_Pin);
			LL_GPIO_SetOutputPin(IRR4_GPIO_Port, IRR4_Pin);
			LL_GPIO_SetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
		};break;
		case R100:
		{
			LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
			LL_GPIO_SetOutputPin(IRR2_GPIO_Port, IRR2_Pin);
			LL_GPIO_SetOutputPin(IRR3_GPIO_Port, IRR3_Pin);
			LL_GPIO_SetOutputPin(IRR4_GPIO_Port, IRR4_Pin);
			LL_GPIO_ResetOutputPin(IRR1_GPIO_Port, IRR1_Pin);
		};break;
		case R1k:
		{
			LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
			LL_GPIO_SetOutputPin(IRR1_GPIO_Port, IRR1_Pin);
			LL_GPIO_SetOutputPin(IRR3_GPIO_Port, IRR3_Pin);
			LL_GPIO_SetOutputPin(IRR4_GPIO_Port, IRR4_Pin);
			LL_GPIO_ResetOutputPin(IRR2_GPIO_Port, IRR2_Pin);
		};break;
		case R10k:
		{
			LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
			LL_GPIO_SetOutputPin(IRR1_GPIO_Port, IRR1_Pin);
			LL_GPIO_SetOutputPin(IRR2_GPIO_Port, IRR2_Pin);
			LL_GPIO_SetOutputPin(IRR4_GPIO_Port, IRR4_Pin);
			LL_GPIO_ResetOutputPin(IRR3_GPIO_Port, IRR3_Pin);
		};break;
		case R100k:
		{
			LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
			LL_GPIO_SetOutputPin(IRR1_GPIO_Port, IRR1_Pin);
			LL_GPIO_SetOutputPin(IRR2_GPIO_Port, IRR2_Pin);
			LL_GPIO_SetOutputPin(IRR3_GPIO_Port, IRR3_Pin);
			LL_GPIO_ResetOutputPin(IRR4_GPIO_Port, IRR4_Pin);
		};break;
	}
}

