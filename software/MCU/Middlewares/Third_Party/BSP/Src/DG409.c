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
		case DG409_S1A:{
							LL_GPIO_ResetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin);
							LL_GPIO_ResetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin);
						};break;
		case DG409_S2A: LL_GPIO_SetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin); break;
		case DG409_S3A: LL_GPIO_SetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin); break;
		case DG409_S4A:{
							LL_GPIO_SetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin);
							LL_GPIO_SetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin);
						}; break;
	}

}
