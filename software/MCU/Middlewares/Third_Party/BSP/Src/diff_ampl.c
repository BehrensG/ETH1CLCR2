/*
 * Diff_Ampl.c
 *
 *  Created on: Mar 5, 2022
 *      Author: grzegorz
 */

#include <diff_ampl.h>

void VDiff_Amplifier(e_vdiff gain)
{
	switch(gain)
	{
		case VDIFF_GAIN1:{
							LL_GPIO_ResetOutputPin(VDIFF0_GPIO_Port, VDIFF0_Pin);
							LL_GPIO_ResetOutputPin(VDIFF1_GPIO_Port, VDIFF1_Pin);
							LL_GPIO_ResetOutputPin(VDIFF2_GPIO_Port, VDIFF2_Pin);
							bsp.config.volt_gain = 1;
							bsp.config.volt_gain_index = 0;
						}break;
		case VDIFF_GAIN10:{
							LL_GPIO_ResetOutputPin(VDIFF0_GPIO_Port, VDIFF0_Pin);
							LL_GPIO_SetOutputPin(VDIFF1_GPIO_Port, VDIFF1_Pin);
							LL_GPIO_ResetOutputPin(VDIFF2_GPIO_Port, VDIFF2_Pin);
							bsp.config.volt_gain = 10;
							bsp.config.volt_gain_index = 1;
						}break;
		case VDIFF_GAIN100:{
							LL_GPIO_ResetOutputPin(VDIFF0_GPIO_Port, VDIFF0_Pin);
							LL_GPIO_SetOutputPin(VDIFF1_GPIO_Port, VDIFF1_Pin);
							LL_GPIO_SetOutputPin(VDIFF2_GPIO_Port, VDIFF2_Pin);
							bsp.config.volt_gain = 100;
							bsp.config.volt_gain_index = 2;
						}break;
		case VDIFF_GAIN1000:{
							LL_GPIO_SetOutputPin(VDIFF0_GPIO_Port, VDIFF0_Pin);
							LL_GPIO_SetOutputPin(VDIFF1_GPIO_Port, VDIFF1_Pin);
							LL_GPIO_SetOutputPin(VDIFF2_GPIO_Port, VDIFF2_Pin);
							bsp.config.volt_gain = 1000;
							bsp.config.volt_gain_index = 3;
						}break;
	}
}

void IDiff_Amplifier(e_idiff gain)
{
	switch(gain)
	{
		case IDIFF_GAIN1:{
							LL_GPIO_ResetOutputPin(IDIFF0_GPIO_Port, IDIFF0_Pin);
							LL_GPIO_ResetOutputPin(IDIFF1_GPIO_Port, IDIFF1_Pin);
							bsp.config.curr_gain = 1;
						}break;
		case IDIFF_GAIN10:{
							LL_GPIO_SetOutputPin(IDIFF0_GPIO_Port, IDIFF0_Pin);
							LL_GPIO_ResetOutputPin(IDIFF1_GPIO_Port, IDIFF1_Pin);
							bsp.config.curr_gain = 10;
						}break;
		case IDIFF_GAIN100:{
							LL_GPIO_SetOutputPin(IDIFF0_GPIO_Port, IDIFF0_Pin);
							LL_GPIO_SetOutputPin(IDIFF1_GPIO_Port, IDIFF1_Pin);
							bsp.config.curr_gain = 100;
						}break;
	}
}
