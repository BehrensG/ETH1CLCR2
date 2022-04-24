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
			bsp.config.resistor_value = 1;
			bsp.config.resistor_index = 0;
		};break;
		case R100:
		{
			LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
			LL_GPIO_SetOutputPin(IRR2_GPIO_Port, IRR2_Pin);
			LL_GPIO_SetOutputPin(IRR3_GPIO_Port, IRR3_Pin);
			LL_GPIO_SetOutputPin(IRR4_GPIO_Port, IRR4_Pin);
			LL_GPIO_ResetOutputPin(IRR1_GPIO_Port, IRR1_Pin);
			bsp.config.resistor_value = 100;
			bsp.config.resistor_index = 1;
		};break;
		case R1k:
		{
			LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
			LL_GPIO_SetOutputPin(IRR1_GPIO_Port, IRR1_Pin);
			LL_GPIO_SetOutputPin(IRR3_GPIO_Port, IRR3_Pin);
			LL_GPIO_SetOutputPin(IRR4_GPIO_Port, IRR4_Pin);
			LL_GPIO_ResetOutputPin(IRR2_GPIO_Port, IRR2_Pin);
			bsp.config.resistor_value = 1000;
			bsp.config.resistor_index = 2;
		};break;
		case R10k:
		{
			LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
			LL_GPIO_SetOutputPin(IRR1_GPIO_Port, IRR1_Pin);
			LL_GPIO_SetOutputPin(IRR2_GPIO_Port, IRR2_Pin);
			LL_GPIO_SetOutputPin(IRR4_GPIO_Port, IRR4_Pin);
			LL_GPIO_ResetOutputPin(IRR3_GPIO_Port, IRR3_Pin);
			bsp.config.resistor_value = 10000;
			bsp.config.resistor_index = 3;
		};break;
		case R100k:
		{
			LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
			LL_GPIO_SetOutputPin(IRR1_GPIO_Port, IRR1_Pin);
			LL_GPIO_SetOutputPin(IRR2_GPIO_Port, IRR2_Pin);
			LL_GPIO_SetOutputPin(IRR3_GPIO_Port, IRR3_Pin);
			LL_GPIO_ResetOutputPin(IRR4_GPIO_Port, IRR4_Pin);
			bsp.config.resistor_value = 100000;
			bsp.config.resistor_index = 4;
		};break;
	}
}

