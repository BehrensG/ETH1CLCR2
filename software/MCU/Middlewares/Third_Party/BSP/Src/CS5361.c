/*
 * CS5361.c
 *
 *  Created on: Mar 5, 2022
 *      Author: grzegorz
 */

#include "CS5361.h"



void CS5361_nReset(uint8_t state)
{
	if(ON == state)
	{
		LL_GPIO_ResetOutputPin(nADC2_RST_GPIO_Port, nADC2_RST_Pin);
	}
	else
	{
		LL_GPIO_SetOutputPin(nADC2_RST_GPIO_Port, nADC2_RST_Pin);
	}
}

void CS5361_ModeSelect(uint8_t mode)
{

}

void CS5361_nHighPassFilter(uint8_t state)
{
	if(ON == state)
	{
		LL_GPIO_ResetOutputPin(nADC2_HPF_GPIO_Port, nADC2_HPF_Pin);
	}
	else
	{
		LL_GPIO_SetOutputPin(nADC2_HPF_GPIO_Port, nADC2_HPF_Pin);
	}
}

void CS5361_MCLKDivider(uint8_t state)
{
	if(ON == state)
	{
		LL_GPIO_SetOutputPin(ADC2_MDIV_GPIO_Port, ADC2_MDIV_Pin);
	}
	else
	{
		LL_GPIO_ResetOutputPin(ADC2_MDIV_GPIO_Port, ADC2_MDIV_Pin);
	}
}

void CS5361_SampleRate(e_sample_rate_t rate)
{
	switch(rate)
	{
	case CS5361_SIGNLE_SPEED:{
								LL_GPIO_ResetOutputPin(ADC2_M0_GPIO_Port, ADC2_M0_Pin);
								LL_GPIO_ResetOutputPin(ADC2_M1_GPIO_Port, ADC2_M1_Pin);
							};break;
	case CS5361_DOUBLE_SPEED:{
								LL_GPIO_SetOutputPin(ADC2_M0_GPIO_Port, ADC2_M0_Pin);
								LL_GPIO_ResetOutputPin(ADC2_M1_GPIO_Port, ADC2_M1_Pin);
							};break;
	case CS5361_QUAD_SPEED:{
								LL_GPIO_ResetOutputPin(ADC2_M0_GPIO_Port, ADC2_M0_Pin);
								LL_GPIO_SetOutputPin(ADC2_M1_GPIO_Port, ADC2_M1_Pin);
							};break;
	}
}

void CS5361_Init()
{
	CS5361_nReset(ON);
	CS5361_SampleRate(CS5361_QUAD_SPEED);
	CS5361_nReset(OFF);
}
