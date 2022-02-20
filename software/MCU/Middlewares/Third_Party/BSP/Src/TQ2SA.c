/*
 * TQ2SA.c
 *
 *  Created on: Feb 20, 2022
 *      Author: grzegorz
 */

#include "TQ2SA.h"

void TQ2A_ADCSelect(tq2sa_mux_e adc)
{
	if(TQ2SA_ADC1 == adc)
	{
		LL_GPIO_ResetOutputPin(ADC_SEL_GPIO_Port, ADC_SEL_Pin);
	}
	else if (TQ2SA_ADC2 == adc)
	{
		LL_GPIO_SetOutputPin(ADC_SEL_GPIO_Port, ADC_SEL_Pin);
	}
}

void TQ2A_VGain10x(uint8_t state)
{
	state ? LL_GPIO_SetOutputPin(VDIFF0_GPIO_Port, VDIFF0_Pin) : LL_GPIO_ResetOutputPin(VDIFF0_GPIO_Port, VDIFF0_Pin);
}

void TQ2A_IVShunt(uint8_t state)
{
	state ? LL_GPIO_SetOutputPin(IRR0_GPIO_Port, IRR0_Pin) : LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin);
}
