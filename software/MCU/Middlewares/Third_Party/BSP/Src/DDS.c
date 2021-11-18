/*
 * DDS.c
 *
 *  Created on: Nov 17, 2021
 *      Author: grzegorz
 */

#include "DDS.h"
#include "main.h"

void DDS_ClockDivider(dds_clk_div_e clk_div)
{
    LL_GPIO_SetOutputPin(DDS_DIV2_GPIO_Port, DDS_DIV2_Pin);
    LL_GPIO_SetOutputPin(DDS_DIV4_GPIO_Port, DDS_DIV4_Pin);
    LL_GPIO_SetOutputPin(DDS_DIV8_GPIO_Port, DDS_DIV8_Pin);
    LL_GPIO_SetOutputPin(nDDS_DIV10_GPIO_Port, nDDS_DIV10_Pin);

	switch(clk_div)
	{
		case DDS_DIV2: LL_GPIO_ResetOutputPin(DDS_DIV2_GPIO_Port, DDS_DIV2_Pin);break;
		case DDS_DIV4: LL_GPIO_ResetOutputPin(DDS_DIV4_GPIO_Port, DDS_DIV4_Pin);break;
		case DDS_DIV8: LL_GPIO_ResetOutputPin(DDS_DIV8_GPIO_Port, DDS_DIV8_Pin);break;
		case DDS_DIV10: LL_GPIO_ResetOutputPin(nDDS_DIV10_GPIO_Port, nDDS_DIV10_Pin);break;
	}
}

