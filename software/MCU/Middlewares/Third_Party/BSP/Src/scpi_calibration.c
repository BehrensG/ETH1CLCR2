/*
 * scpi_calibration.c
 *
 *  Created on: Nov 20, 2021
 *      Author: grzegorz
 */

#include <stdio.h>

#include "scpi_calibration.h"
#include "bsp.h"
#include "ADS8681.h"
#include "diff_ampl.h"
#include "eeprom.h"
#include "IV_Converter.h"
#include "relays.h"


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

scpi_choice_def_t adc_select[] =
{
    {"ADC1", ADC_ADS8681},
    {"ADC2", ADC_CS5361},
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
		max_val = largets_double(bsp.measure.voltage.wave, bsp.config.ads8681.sample_size);

	}
	else if(ADC_CS5361 == bsp.config.adc_select)
	{

	}

	gain_correction = reference/max_val;

	return gain_correction;

}

float fequal(float a, float b)
{
 return (fabs(a-b) == 0.0);
}

static uint8_t check_voltage(float source_voltage)
{
	float valid_voltages[] = {1.0, 0.1, 0.01};

	for(uint8_t x = 0; x < 3; x++)
	{
		if(fequal(valid_voltages[x], source_voltage))
		{
			return 1;
		}
	}

	return 0;
}


static double curr_gain_correction(double reference, uint16_t gain)
{
	double max_val = 0, gain_correction = 0;

	if(ADC_ADS8681 == bsp.config.adc_select)
	{
		max_val = largets_double(bsp.measure.current.wave, bsp.config.ads8681.sample_size);

	}
	else if(ADC_CS5361 == bsp.config.adc_select)
	{

	}

	gain_correction = reference/max_val;

	return gain_correction;

}

static uint8_t check_resistor_range(uint32_t range)
{
	uint32_t ranges[] = {1, 100, 1000, 10000, 100000};

	for(uint8_t x = 0; x < 5; x++)
	{
		if(ranges[x] == range)
		{
			return 1;
		}
	}

	return 0;
}

static uint8_t check_gain(int32_t gain)
{
	int32_t valid_gain[] = {1, 10, 100};

	for(uint8_t x = 0; x < 3; x++)
	{
		if(valid_gain[x] == gain)
		{
			return 1;
		}
	}

	return 0;
}

scpi_result_t SCPI_CalibrationADCQ(scpi_t * context)
{
	int32_t calib_type = CALIB_VOLT;
	int32_t adc = ADC_ADS8681;
	float source_voltage = 0.0;
	float source_current = 0.0;
	float source_freq = 0.0;
	int32_t gain = 0;
	uint32_t resistor_value = 1000;

	// Select the ADC
	if(!SCPI_ParamChoice(context, adc_select, &adc, TRUE))
	{
		return SCPI_RES_ERR;
	}

	// Select if voltage or current measurement will be calibrated
	if(!SCPI_ParamChoice(context, calib_type_select, &calib_type, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(CALIB_VOLT == calib_type)
	{
		if(!SCPI_ParamInt32(context, &gain, TRUE))
		{
			return SCPI_RES_ERR;
		}

		if(!SCPI_ParamFloat(context, &source_voltage, TRUE))
		{
			return SCPI_RES_ERR;
		}

		if(!SCPI_ParamFloat(context, &source_freq, TRUE))
		{
			return SCPI_RES_ERR;
		}

		if(check_voltage(source_voltage) && check_gain(gain))
		{
			CXN_Relays_AllOn();
			HAL_Delay(20);
			VDiff_Amplifier(gain);
			bsp.config.frequency = source_freq;
			HAL_Delay(20);

			if(ADC_ADS8681 == adc)
			{
				bsp.config.adc_select = ADC_ADS8681;
				ADS8681_Measurement();
				bsp.eeprom.structure.calib_ads8681_volt.gain[bsp.config.volt_gain_index] = volt_gain_correction(source_voltage, gain);
			}
			else if (ADC_CS5361 == adc)
			{

			}

			CXN_Relays_AllOff();
			HAL_Delay(20);
		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE);
			return SCPI_RES_ERR;
		}

	}
	else if (CALIB_CURR == calib_type)
	{
		if(!SCPI_ParamFloat(context, &source_current, TRUE))
		{
			return SCPI_RES_ERR;
		}

		if(!SCPI_ParamFloat(context, &source_freq, TRUE))
		{
			return SCPI_RES_ERR;
		}

		if(!SCPI_ParamUInt32(context, &resistor_value, TRUE))
		{
			return SCPI_RES_ERR;
		}

		if(check_resistor_range(resistor_value) && check_gain(gain))
		{
			CXN_Relays_AllOn();
			HAL_Delay(20);
			IDiff_Amplifier(gain);
			IV_Converter(resistor_value);
			bsp.config.frequency = source_freq;
			HAL_Delay(20);

			if(ADC_ADS8681 == adc)
			{
				bsp.config.adc_select = ADC_ADS8681;
				ADS8681_Measurement();
				bsp.eeprom.structure.calib_ads8681_curr.gain[bsp.config.curr_gain_index][bsp.config.resistor_index] = curr_gain_correction(source_current, gain);
			}
			else if (ADC_CS5361 == adc)
			{
			}

			CXN_Relays_AllOff();
			HAL_Delay(20);

		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE);
			return SCPI_RES_ERR;
		}
	}


	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationSourceQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationALLQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationCountQ(scpi_t * context)
{
	SCPI_ResultUInt32(context,bsp.eeprom.structure.calibration_count);
	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationDateQ(scpi_t * context)
{
	char buffer[24] = {0};

	snprintf(buffer,sizeof(buffer), "%02d.%02d.%d %02d:%02d:%02d", bsp.eeprom.structure.calib_date.day, bsp.eeprom.structure.calib_date.month, bsp.eeprom.structure.calib_date.year,
																 bsp.eeprom.structure.calib_date.hour, bsp.eeprom.structure.calib_date.minute, bsp.eeprom.structure.calib_date.second);
	SCPI_ResultCharacters(context, buffer, strlen(buffer));

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


	if(bsp.calibration.status)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_CALIBRATION_MEMORY_SECURE);
		return SCPI_RES_ERR;
	}

	++bsp.eeprom.structure.calibration_count;

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
