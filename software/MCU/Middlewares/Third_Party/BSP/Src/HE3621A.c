/*
 * HE3621A.c
 *
 *  Created on: Feb 20, 2022
 *      Author: grzegorz
 */

#include "HE3621A.h"


void HE3621A_Mux(he3621a_mux_e relay, uint8_t state)
{
	uint8_t select = 0, shift = 0x01;

	for(uint8_t i = 0; i < HE3621_REL_COUNT; i++)
	{
		shift = shift << 1;
		select = relay & shift;

		switch(select)
		{
			case HE3621A_H_CUR: state ? LL_GPIO_SetOutputPin(CXN_REL1_GPIO_Port, CXN_REL1_Pin) : LL_GPIO_ResetOutputPin(CXN_REL1_GPIO_Port, CXN_REL1_Pin); break;
			case HE3621A_L_CUR:	state ? LL_GPIO_SetOutputPin(CXN_REL2_GPIO_Port, CXN_REL2_Pin) : LL_GPIO_ResetOutputPin(CXN_REL2_GPIO_Port, CXN_REL2_Pin); break;
			case HE3621A_GND_C:	state ? LL_GPIO_SetOutputPin(CXN_REL3_GPIO_Port, CXN_REL3_Pin) : LL_GPIO_ResetOutputPin(CXN_REL3_GPIO_Port, CXN_REL3_Pin); break;
			case HE3621A_GND_D:	state ? LL_GPIO_SetOutputPin(CXN_REL4_GPIO_Port, CXN_REL4_Pin) : LL_GPIO_ResetOutputPin(CXN_REL4_GPIO_Port, CXN_REL4_Pin); break;
			case HE3621A_H_POT:	state ? LL_GPIO_SetOutputPin(CXN_REL5_GPIO_Port, CXN_REL5_Pin) : LL_GPIO_ResetOutputPin(CXN_REL5_GPIO_Port, CXN_REL5_Pin); break;
			case HE3621A_L_POT:	state ? LL_GPIO_SetOutputPin(CXN_REL6_GPIO_Port, CXN_REL6_Pin) : LL_GPIO_ResetOutputPin(CXN_REL6_GPIO_Port, CXN_REL6_Pin); break;
		}
	}
}

void HE3621A_Mux_AllOn()
{
	LL_GPIO_SetOutputPin(CXN_REL1_GPIO_Port, CXN_REL1_Pin);
	LL_GPIO_SetOutputPin(CXN_REL2_GPIO_Port, CXN_REL2_Pin);
	LL_GPIO_SetOutputPin(CXN_REL3_GPIO_Port, CXN_REL3_Pin);
	LL_GPIO_SetOutputPin(CXN_REL4_GPIO_Port, CXN_REL4_Pin);
	LL_GPIO_SetOutputPin(CXN_REL5_GPIO_Port, CXN_REL5_Pin);
	LL_GPIO_SetOutputPin(CXN_REL6_GPIO_Port, CXN_REL6_Pin);
}

void HE3621A_Mux_AllOff()
{
	LL_GPIO_ResetOutputPin(CXN_REL1_GPIO_Port, CXN_REL1_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL2_GPIO_Port, CXN_REL2_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL3_GPIO_Port, CXN_REL3_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL4_GPIO_Port, CXN_REL4_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL5_GPIO_Port, CXN_REL5_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL6_GPIO_Port, CXN_REL6_Pin);
}
