/*
 * CS5361.c
 *
 *  Created on: Mar 5, 2022
 *      Author: grzegorz
 */

#include "CS5361.h"

extern I2S_HandleTypeDef hi2s2;


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
	__IO int32_t tmp_meas[512];
	CS5361_nReset(ON);
	CS5361_SampleRate(CS5361_QUAD_SPEED);
	CS5361_nReset(OFF);
	HAL_Delay(10);
	HAL_I2S_Receive(&hi2s2, tmp_meas, 512, 10000);
}

BSP_StatusTypeDef CS5361_Measure()
{
	uint16_t adc_readout = 2*WAV_LEN_MAX;
	int32_t adc_values[adc_readout];
	uint16_t k1 = 0, k2 = 0;
	int32_t volt_values[WAV_LEN_MAX];
	int32_t curr_values[WAV_LEN_MAX];
	BSP_StatusTypeDef status;

	status = HAL_I2S_Receive(&hi2s2, adc_values, 5, 20000);
	if(BSP_OK != status){return status;}

	status = HAL_I2S_Receive(&hi2s2, adc_values, adc_readout, 20000);
	if(BSP_OK != status){return status;}

	for(uint16_t x=0; x < (adc_readout - 1); x++)
	{
		if(0 == (x % 2))
		{
			curr_values[k1++] = adc_values[x];
		}
		else
		{
			volt_values[k2++] = adc_values[x];
		}
	}

	for(uint16_t x=0; x < (WAV_LEN_MAX - 1); x++)
	{
		if(volt_values[x] & 0x800000)
		{
			volt_values[x] |= 0xFF000000;
		}

		bsp.measure.voltage.wave[x] = (double)(volt_values[x]*CS5361_RES*bsp.eeprom.structure.calib_cs5361_volt.gain[bsp.config.volt_gain_index]);

		if(curr_values[x] & 0x800000)
		{
			curr_values[x] |= 0xFF000000;
		}

		bsp.measure.current.wave[x] = (double)(curr_values[x]*CS5361_RES*bsp.eeprom.structure.calib_cs5361_curr.gain[bsp.config.curr_gain_index]);
		bsp.measure.current.wave[x] = (double)(-1*bsp.measure.current.wave[x]);
	}

	return status;
}

