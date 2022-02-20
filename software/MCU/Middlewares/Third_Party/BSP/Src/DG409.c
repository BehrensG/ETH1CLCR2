/*
 * DG409.c
 *
 *  Created on: Feb 20, 2022
 *      Author: grzegorz
 */


#include "DG409.h"

void DG409_MUX(dg409_channel_e channel)
{

	LL_GPIO_ResetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin);
	LL_GPIO_ResetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin);


	switch(channel)
	{
		case DG409_SA1:
						{
							LL_GPIO_ResetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin);
							LL_GPIO_ResetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin);
						};break;
		case DG409_SA2: LL_GPIO_SetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin); break;
		case DG409_SA3: LL_GPIO_SetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin); break;
		case DG409_SA4:
						{
							LL_GPIO_SetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin);
							LL_GPIO_SetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin);
						}; break;
	}

}
