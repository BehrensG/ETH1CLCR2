/*
 * DDS.c
 *
 *  Created on: Nov 17, 2021
 *      Author: grzegorz
 */

#include "DDS.h"
#include "main.h"
#include "AD9834.h"

void DDS_ClockDivider(dds_clk_div_e clk_div)
{
	switch(clk_div)
	{
		case DDS_DIV0:
			{
				LL_GPIO_SetOutputPin(DDS_DIV2_GPIO_Port, DDS_DIV2_Pin);
				LL_GPIO_SetOutputPin(DDS_DIV4_GPIO_Port, DDS_DIV4_Pin);
				LL_GPIO_SetOutputPin(DDS_DIV8_GPIO_Port, DDS_DIV8_Pin);
				LL_GPIO_SetOutputPin(nDDS_DIV10_GPIO_Port, nDDS_DIV10_Pin);

				bsp.dds.divider = DDS_DIV0;
			};break;

		case DDS_DIV2:
		{
				LL_GPIO_ResetOutputPin(DDS_DIV2_GPIO_Port, DDS_DIV2_Pin);
				bsp.dds.divider = DDS_DIV2;
		};break;

		case DDS_DIV4:
			{
				LL_GPIO_ResetOutputPin(DDS_DIV4_GPIO_Port, DDS_DIV4_Pin);
				bsp.dds.divider = DDS_DIV4;
			}break;

		case DDS_DIV8:
		{
				LL_GPIO_ResetOutputPin(DDS_DIV8_GPIO_Port, DDS_DIV8_Pin);
				bsp.dds.divider = DDS_DIV8;
			}break;

		case DDS_DIV10:
			{
				LL_GPIO_ResetOutputPin(nDDS_DIV10_GPIO_Port, nDDS_DIV10_Pin);
				bsp.dds.divider = DDS_DIV10;
			}break;
	}
}

static uint32_t DDS_ConvertFrequency(float freq)
{
	uint32_t freq28 = 0x00;

	switch(bsp.dds.divider)
	{
		case DDS_DIV0: freq28 = (uint32_t)((float)freq / DDS_DIV0_RES);break;
		case DDS_DIV2: freq28 = (uint32_t)((float)freq / DDS_DIV2_RES);break;
		case DDS_DIV4: freq28 = (uint32_t)((float)freq / DDS_DIV4_RES);break;
		case DDS_DIV8: freq28 = (uint32_t)((float)freq / DDS_DIV8_RES);break;
		case DDS_DIV10: freq28 = (uint32_t)((float)freq / DDS_DIV10_RES);break;
	}

	return freq28;
}

void DDS_SetFrequency(float freq)
{
	uint32_t freq28 = DDS_ConvertFrequency(freq);
	AD9834_SetFrequency(freq28);
}
