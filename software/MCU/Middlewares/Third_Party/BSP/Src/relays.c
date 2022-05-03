/*
 * relays.c
 *
 *  Created on: Nov 14, 2021
 *      Author: grzegorz
 */


#include "relays.h"

void CXN_Relays_AllOn(void)
{

	LL_GPIO_SetOutputPin(CXN_REL1_GPIO_Port, CXN_REL1_Pin);
	LL_GPIO_SetOutputPin(CXN_REL2_GPIO_Port, CXN_REL2_Pin);
	LL_GPIO_SetOutputPin(CXN_REL3_GPIO_Port, CXN_REL3_Pin);
	LL_GPIO_SetOutputPin(CXN_REL4_GPIO_Port, CXN_REL4_Pin);
	LL_GPIO_SetOutputPin(CXN_REL5_GPIO_Port, CXN_REL5_Pin);
	LL_GPIO_SetOutputPin(CXN_REL6_GPIO_Port, CXN_REL6_Pin);

}

void CXN_Relays_Control(int32_t relay, uint8_t state)
{

	switch(relay)
	{
		case 0: (ON == state) ? LL_GPIO_SetOutputPin(CXN_REL1_GPIO_Port, CXN_REL1_Pin) : LL_GPIO_ResetOutputPin(CXN_REL1_GPIO_Port, CXN_REL1_Pin); break;
		case 1: (ON == state) ? LL_GPIO_SetOutputPin(CXN_REL2_GPIO_Port, CXN_REL2_Pin) : LL_GPIO_ResetOutputPin(CXN_REL2_GPIO_Port, CXN_REL2_Pin); break;
		case 2: (ON == state) ? LL_GPIO_SetOutputPin(CXN_REL3_GPIO_Port, CXN_REL3_Pin) : LL_GPIO_ResetOutputPin(CXN_REL3_GPIO_Port, CXN_REL3_Pin); break;
		case 3: (ON == state) ? LL_GPIO_SetOutputPin(CXN_REL4_GPIO_Port, CXN_REL4_Pin) : LL_GPIO_ResetOutputPin(CXN_REL4_GPIO_Port, CXN_REL4_Pin); break;
		case 4: (ON == state) ? LL_GPIO_SetOutputPin(CXN_REL5_GPIO_Port, CXN_REL5_Pin) : LL_GPIO_ResetOutputPin(CXN_REL5_GPIO_Port, CXN_REL5_Pin); break;
		case 5: (ON == state) ? LL_GPIO_SetOutputPin(CXN_REL6_GPIO_Port, CXN_REL6_Pin) : LL_GPIO_ResetOutputPin(CXN_REL6_GPIO_Port, CXN_REL6_Pin); break;
	}

}

void CXN_Relays_AllOff(void)
{

	LL_GPIO_ResetOutputPin(CXN_REL1_GPIO_Port, CXN_REL1_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL2_GPIO_Port, CXN_REL2_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL3_GPIO_Port, CXN_REL3_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL4_GPIO_Port, CXN_REL4_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL5_GPIO_Port, CXN_REL5_Pin);
	LL_GPIO_ResetOutputPin(CXN_REL6_GPIO_Port, CXN_REL6_Pin);

}

void TQ2SA_Relays(uint8_t relay, uint8_t state)
{
	switch(relay)
	{
		case IRR0: (ON == state) ? LL_GPIO_SetOutputPin(IRR0_GPIO_Port, IRR0_Pin) : LL_GPIO_ResetOutputPin(IRR0_GPIO_Port, IRR0_Pin); break;
		case VDIFF0: (ON == state) ? LL_GPIO_SetOutputPin(VDIFF0_GPIO_Port, VDIFF0_Pin) : LL_GPIO_ResetOutputPin(VDIFF0_GPIO_Port, VDIFF0_Pin); break;
		case ADC_SEL: if(ON == state)
						{
							LL_GPIO_SetOutputPin(ADC_SEL_GPIO_Port, ADC_SEL_Pin);
							bsp.config.adc_select = ADC_CS5361;
						}
						else
						{
							LL_GPIO_ResetOutputPin(ADC_SEL_GPIO_Port, ADC_SEL_Pin);
							bsp.config.adc_select = ADC_ADS8681;
						}; break;

	}
}

void SN74LVC1G3157_AnalogSwitch(uint8_t analog_switch, uint8_t b_state)
{
	switch(analog_switch)
	{
		case IDIFF0: (B2 == b_state) ? LL_GPIO_SetOutputPin(IDIFF0_GPIO_Port, IDIFF0_Pin) : LL_GPIO_ResetOutputPin(IDIFF0_GPIO_Port, IDIFF0_Pin); break;
		case IDIFF1: (B2 == b_state) ? LL_GPIO_SetOutputPin(IDIFF1_GPIO_Port, IDIFF1_Pin) : LL_GPIO_ResetOutputPin(IDIFF1_GPIO_Port, IDIFF1_Pin); break;
		case VDIFF1: (B2 == b_state) ? LL_GPIO_SetOutputPin(VDIFF1_GPIO_Port, VDIFF1_Pin) : LL_GPIO_ResetOutputPin(VDIFF1_GPIO_Port, VDIFF1_Pin); break;
		case VDIFF2: (B2 == b_state) ? LL_GPIO_SetOutputPin(VDIFF1_GPIO_Port, VDIFF1_Pin) : LL_GPIO_ResetOutputPin(VDIFF1_GPIO_Port, VDIFF1_Pin); break;
	}

}

void DG409_AnalogSwitch(uint8_t analog_switch)
{

	switch(analog_switch)
	{
		case S1A:
		{
			LL_GPIO_ResetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin);
			LL_GPIO_ResetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin);
			HAL_Delay(2);
		}break;

		case S2A:
		{
			LL_GPIO_SetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin);
			LL_GPIO_ResetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin);
			HAL_Delay(2);
		}break;

		case S3A:
		{
			LL_GPIO_ResetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin);
			LL_GPIO_SetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin);
			HAL_Delay(2);
		}break;

		case S4A:
		{
			LL_GPIO_SetOutputPin(MUX_A0_GPIO_Port, MUX_A0_Pin);
			LL_GPIO_SetOutputPin(MUX_A1_GPIO_Port, MUX_A1_Pin);
			HAL_Delay(2);
		}break;
	}

}

