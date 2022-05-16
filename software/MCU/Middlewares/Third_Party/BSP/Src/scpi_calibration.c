/*
 * scpi_calibration.c
 *
 *  Created on: Nov 20, 2021
 *      Author: grzegorz
 */

#include "scpi_calibration.h"
#include "bsp.h"

scpi_choice_def_t calib_state_select[] =
{
    {"OFF", 0},
    {"ON", 1},
	{"0", 0},
	{"1", 1},
    SCPI_CHOICE_LIST_END
};



scpi_choice_def_t calib_type_select[] =
{
    {"VOLtage", CALIB_VOLT},
    {"CURRent", CALIB_CURR},
    SCPI_CHOICE_LIST_END
};

static double largets_double(double array[], uint32_t length)
{
    double max = fabs(array[0]);


    for( uint32_t i =1; i < length; i++)
    {
    	if(fabs(array[i]) > max)
    	{
    		max = fabs(array[i]);
        }
    }

    return max;
}

static double volt_gain_correction(double reference, uint16_t gain)
{
	double max_val = 0, gain_correction = 0;

	if(ADC_ADS8681 == bsp.config.adc_select)
	{
		max_val = largets_double(bsp.measure.voltage, bsp.config.ads8681.sample_size);

	}
	else if(ADC_CS5361 == bsp.config.adc_select)
	{

	}

	gain_correction = reference/max_val;

	return gain_correction;

}

static double curr_gain_correction(double reference, uint16_t gain, uint32_t resistor)
{
	double max_val = 0, gain_correction = 0;

	if(ADC_ADS8681 == bsp.config.adc_select)
	{
		max_val = largets_double(bsp.measure.current, bsp.config.ads8681.sample_size);

	}
	else if(ADC_CS5361 == bsp.config.adc_select)
	{

	}

	gain_correction = reference/max_volt;

	return gain_correction;

}

scpi_result_t SCPI_CalibrationADCQ(scpi_t * context)
{
	int32 calib_type = CALIB_VOLT;
	float source_voltage = 0.0;
	float source_current = 0.0;
	float source_freq = 0.0;

	if(!SCPI_ParamChoice(context, calib_type_select, &state, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(CALIB_VOLT == calib_type)
	{
		if(!SCPI_ParamFloat(context, &source_voltage, TRUE))
		{
			return SCPI_RES_ERR;
		}
	}
	else
	{
		if(!SCPI_ParamFloat(context, &source_current, TRUE))
		{
			return SCPI_RES_ERR;
		}
	}


	if(!SCPI_ParamFloat(context, &source_voltage, TRUE))
	{
		return SCPI_RES_ERR;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationALLQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationCountQ(scpi_t * context)
{
	char buffer[6] = {0};

	snprintf(buffer,sizeof(buffer), "%d", bsp.eeprom.structure.calibration_count);
	SCPI_ResultCharacters(context, buffer, strlen(buffer));

	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationDateQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationSecureState(scpi_t * context)
{
	int32_t state = 1;
	int8_t password_read[PASSWORD_LENGTH] = {0};
	size_t length = 0;
	int8_t* password_reference = bsp.eeprom.structure.password;

	if(!SCPI_ParamChoice(context, calib_state_select, &state, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamCopyText(context, (char*)password_read, PASSWORD_LENGTH, &length, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!strcmp((const char*)password_read, (const char*)password_reference))
	{
		bsp.calibration.status = state;
	}
	else
	{
		SCPI_ErrorPush(context, SCPI_ERROR_SERVICE_INVALID_PASSWORD);
		return SCPI_RES_ERR;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationSecureStateQ(scpi_t * context)
{
	SCPI_ResultUInt8(context, bsp.calibration.status);
	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationStore(scpi_t * context)
{
	size_t channel_size = 0;
	uint8_t index = 0;


	if(bsp.calibration.status)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_CALIBRATION_MEMORY_SECURE);
		return SCPI_RES_ERR;
	}

	if(BSP_OK == EEPROM_Write(&bsp.eeprom, EEPROM_CFG_SIZE))
	{
		return SCPI_RES_OK;
	}
	else
	{
		SCPI_ErrorPush(context, SCPI_ERROR_SYSTEM_ERROR);
		return SCPI_RES_ERR;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationValue(scpi_t * context)
{
	return SCPI_RES_OK;
}
