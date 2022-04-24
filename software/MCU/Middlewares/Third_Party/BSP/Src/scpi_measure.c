/*
 * scpi_measure.c
 *
 *  Created on: Nov 20, 2021
 *      Author: grzegorz
 */


#include "scpi_measure.h"
#include "DDS.h"

scpi_result_t SCPI_MeasureResultQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureFrequency(scpi_t * context)
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
				bsp.config.frequency = freq.content.value;
				DDS_SetFrequency(freq.content.value);
				return SCPI_RES_OK;
			}
		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_INVALID_SUFFIX);
			return SCPI_RES_ERR;
		}
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureFrequencyQ(scpi_t * context)
{
	SCPI_ResultFloat(context, bsp.config.frequency);
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureLevel(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureLevelQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureSpeed(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureSpeedQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureFunction(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureFunctionQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureNominal(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureNominalQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureOutput(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_MeasureOutputQ(scpi_t * context)
{
	return SCPI_RES_OK;
}
