/*
 * scpi_sense.c
 *
 *  Created on: Apr 30, 2022
 *      Author: grzegorz
 */

#include "scpi_sense.h"
#include "IV_Converter.h"

scpi_choice_def_t Function_select[] =
{
    {"FIMPedance", FIMP},
    {"FADMittance", FADM},
    SCPI_CHOICE_LIST_END
};


scpi_result_t SCPI_SenseFunction(scpi_t * context)
{
	int32_t value = 0;

	if(!SCPI_ParamChoice(context, Function_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}

	bsp.config.function = value;

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseFunctionQ(scpi_t * context)
{
	if(FIMP == bsp.config.function)
	{
		SCPI_ResultCharacters(context, "FIMP", 4);
	}
	else
	{
		SCPI_ResultCharacters(context, "FADM", 4);
	}

	return SCPI_RES_OK;
}

static uint8_t check_range(uint32_t range)
{
	uint32_t ranges[] = {1, 100, 1000, 10000, 100000};

	for(uint8_t x = 0; x < 5; x++)
	{
		if(ranges[x] == range)
		{
			return 0;
		}
	}

	return 1;
}

scpi_result_t SCPI_SenseFImpedanceRangeUpper(scpi_t * context)
{
	scpi_number_t range;

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &range, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(range.special)
	{
		switch(range.content.tag)
		{
		case SCPI_NUM_MIN: bsp.config.range = MIN_RANGE; break;
		case SCPI_NUM_MAX: bsp.config.range = MAX_RANGE; break;
		case SCPI_NUM_DEF: bsp.config.range = DEF_RANGE; break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == range.unit || SCPI_UNIT_UNITLESS == range.unit)
		{
			if(check_range(bsp.config.range))
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{

			}
		}
		else if(SCPI_UNIT_OHM == range.unit)
		{

		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_INVALID_SUFFIX);
			return SCPI_RES_ERR;
		}
	}

	bsp.config.range = (uint32_t)range.content.value;
	IV_Converter(bsp.config.range);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseFImpedanceRangeUpperQ(scpi_t * context)
{
	SCPI_ResultUInt32(context, bsp.config.range);
	return SCPI_RES_OK;
}
