/*
 * scpi_measure.c
 *
 *  Created on: Nov 20, 2021
 *      Author: grzegorz
 */


#include "scpi_source.h"
#include "scpi_def.h"

#include "DDS.h"
#include "DAC7811.h"
#include "relays.h"


/*
 * SOURce:FREQuency[:CW] <frequency value>
 *
 * @INFO:
 * Set the source frequency value.
 *
 * @PARAMETERS:
 * 				<frequency value>		Frequency value from 20 to 100000 Hz.
 * 				MIN						20 Hz
 * 				MAX						100000 Hz
 * 				DEF						1000 Hz
 *
 */

scpi_result_t SCPI_SourceFrequency(scpi_t * context)
{
	scpi_number_t freq;

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &freq, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(freq.special)
	{
		switch(freq.content.tag)
		{
		case SCPI_NUM_MIN: bsp.config.frequency = MIN_FREQ; break;
		case SCPI_NUM_MAX: bsp.config.frequency = MAX_FREQ; break;
		case SCPI_NUM_DEF: bsp.config.frequency = DEF_FREQ; break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == freq.unit || SCPI_UNIT_UNITLESS == freq.unit)
		{
			if(freq.content.value < MIN_FREQ || freq.content.value > MAX_FREQ)
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{

			}
		}
		else if(SCPI_UNIT_HERTZ == freq.unit)
		{

		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_INVALID_SUFFIX);
			return SCPI_RES_ERR;
		}
	}

	bsp.config.frequency = freq.content.value;
	DDS_SetFrequency(freq.content.value);

	return SCPI_RES_OK;
}

/*
 * SOURce:FREQuency?
 *
 * @INFO:
 * Read the current frequency value.
 *
 */

scpi_result_t SCPI_SourceFrequencyQ(scpi_t * context)
{
	SCPI_ResultFloat(context, bsp.config.frequency);
	return SCPI_RES_OK;
}

scpi_result_t SCPI_SourceVoltage(scpi_t * context)
{
	scpi_number_t volt;

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &volt, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(volt.special)
	{
		switch(volt.content.tag)
		{
		case SCPI_NUM_MIN: bsp.config.voltage = MIN_VOLT; break;
		case SCPI_NUM_MAX: bsp.config.voltage = MAX_VOLT; break;
		case SCPI_NUM_DEF: bsp.config.voltage = DEF_VOLT; break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == volt.unit || SCPI_UNIT_UNITLESS == volt.unit)
		{
			if(volt.content.value < MIN_VOLT || volt.content.value > MAX_VOLT)
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{

			}
		}
		else if (SCPI_UNIT_VOLT == volt.unit)
		{

		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_INVALID_SUFFIX);
			return SCPI_RES_ERR;
		}

	}

	bsp.config.voltage = volt.content.value;
	DAC7811_SetVoltage(bsp.config.voltage);
	DDS_Attenuation(AT_0dBV);


	return SCPI_RES_OK;
}

scpi_result_t SCPI_SourceVoltageQ(scpi_t * context)
{
	SCPI_ResultFloat(context, bsp.config.voltage);
	return SCPI_RES_OK;
}



scpi_result_t SCPI_SourceRelayOutput(scpi_t * context)
{
	scpi_channel_value_t array[MAXCOL*MAXROW] = {0};
	size_t channel_size = 0;
	uint8_t index = 0;
	scpi_bool_t state = 0;

	channel_size = SCPI_GetChannels(context, array);

	if(!channel_size || (channel_size > MAXROW))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamBool(context, &state, TRUE))
	{
		return SCPI_RES_ERR;
	}

	for(uint8_t i = 0; i < channel_size; i++)
	{
		index = array[i].row;
		CXN_Relays_Control(index, state);
		bsp.config.relay.state[index] = (uint8_t)state;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SourceRelayOutputQ(scpi_t * context)
{
	SCPI_ResultArrayUInt8(context, bsp.config.relay.state, MAXROW, SCPI_FORMAT_NORMAL);
	return SCPI_RES_OK;
}
