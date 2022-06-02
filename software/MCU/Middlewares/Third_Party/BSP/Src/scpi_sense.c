/*
 * scpi_sense.c
 *
 *  Created on: Apr 30, 2022
 *      Author: grzegorz
 */

#include "scpi_sense.h"
#include "IV_Converter.h"
#include "result.h"

scpi_choice_def_t function_select[] =
{
    {"FIMPedance", FIMP},
    {"FADMittance", FADM},
    SCPI_CHOICE_LIST_END
};

scpi_choice_def_t correction_select[] =
{
    {"OPEN", COMP_OPEN},
    {"SHORT", COMP_SHORT},
    SCPI_CHOICE_LIST_END
};

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


scpi_result_t SCPI_SenseFunction(scpi_t * context)
{
	int32_t value = 0;

	if(!SCPI_ParamChoice(context, function_select, &value, TRUE))
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
		SCPI_ResultCharacters(context, function_select[0].name, strlen(function_select[0].name));
	}
	else
	{
		SCPI_ResultCharacters(context, function_select[1].name, strlen(function_select[1].name));
	}

	return SCPI_RES_OK;
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
		case SCPI_NUM_MIN: bsp.config.resistor_value = MIN_RANGE; break;
		case SCPI_NUM_MAX: bsp.config.resistor_value = MAX_RANGE; break;
		case SCPI_NUM_DEF: bsp.config.resistor_value = DEF_RANGE; break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == range.unit || SCPI_UNIT_UNITLESS == range.unit)
		{
			if(check_range(range.content.value))
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

	IV_Converter(range.content.value);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseFImpedanceRangeUpperQ(scpi_t * context)
{
	SCPI_ResultUInt32(context, bsp.config.resistor_value);
	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseCorrectionCollectAcquire(scpi_t * context)
{
	int32_t comp_state = 0;

	if(!SCPI_ParamChoice(context, correction_select, &comp_state, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(COMP_OPEN == comp_state)
	{
		bsp.compensate.comp_open = COMP_ON;
	}
	else if (COMP_SHORT == comp_state)
	{
		bsp.compensate.comp_short = COMP_ON;
	}

	Result_Compensate();

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseCorrectionCollectAcquireQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseCorrectionState(scpi_t * context)
{
	scpi_bool_t comp_state;

	if(!SCPI_ParamBool(context, &comp_state, TRUE))
	{
		return SCPI_RES_ERR;
	}

	bsp.compensate.comp_state = (uint8_t)comp_state;

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseCorrectionStateQ(scpi_t * context)
{
	SCPI_ResultBool(context, bsp.compensate.comp_state);
	return SCPI_RES_OK;
}

