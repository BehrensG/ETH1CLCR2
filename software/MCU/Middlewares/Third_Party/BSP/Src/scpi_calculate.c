/*
 * scpi_calculate.c
 *
 *  Created on: Apr 30, 2022
 *      Author: grzegorz
 */

#include "scpi_calculate.h"

scpi_choice_def_t calculation_select[] =
{
	{"NONE", NONE},
    {"REAL", REAL},
    {"IMAGinary", IMAG},
	{"MLINear", MLIN},
	{"PHASe", PHAS},
	{"CP", CP},
	{"CS", CS},
	{"LP", LP},
	{"LS", LS},
	{"D", D},
	{"Q", Q},
	{"RP", RP},
	{"Y", Y},
	{"G", G},
	{"B", B},
    SCPI_CHOICE_LIST_END
};

scpi_choice_def_t nominal_select[] =
{
	{"NONE", NONE},
    {"R", R},
    {"L", L},
	{"C", C},
    SCPI_CHOICE_LIST_END
};

scpi_result_t SCPI_CalculateFormat(scpi_t * context)
{
	int32_t format1 = NONE, format2 = NONE;

	if(!SCPI_ParamChoice(context, calculation_select, &format1, TRUE))
	{

		return SCPI_RES_ERR;
	}


	if(!SCPI_ParamChoice(context, calculation_select, &format2, TRUE))
	{
		return SCPI_RES_ERR;
	}

	bsp.config.format1 = format1;
	bsp.config.format2 = format2;

	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalculateFormatQ(scpi_t * context)
{
	SCPI_ResultCharacters(context, calculation_select[bsp.config.format1].name, strlen(calculation_select[bsp.config.format1].name));
	SCPI_ResultCharacters(context, calculation_select[bsp.config.format2].name, strlen(calculation_select[bsp.config.format2].name));
	return SCPI_RES_OK;
}

static uint8_t check_unit(int32_t type, scpi_number_t* value)
{
	uint8_t status = 0;

	if (R == type)
	{
		(SCPI_UNIT_OHM == value->unit) ? (status = 1) : (status = 0);
	}
	else if (C == type)
	{
		(SCPI_UNIT_FARAD == value->unit) ? (status = 1) : (status = 0);
	}
	else if (L == type)
	{
		(SCPI_UNIT_HENRY == value->unit) ? (status = 1) : (status = 0);
	}
	else
	{
		status = 0;
	}

	return status;
}

scpi_result_t SCPI_CalculateLimitNominal(scpi_t * context)
{
	int32_t type = NONE;
	scpi_number_t value;

	if(!SCPI_ParamChoice(context, nominal_select, &type, TRUE))
	{

		return SCPI_RES_ERR;
	}


	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(SCPI_UNIT_NONE == value.unit || SCPI_UNIT_UNITLESS == value.unit)
	{
		if(value.content.value < 0 || value.content.value > 100000001)
		{
			SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
			return SCPI_RES_ERR;
		}
		else
		{

		}
	}
	else if(check_unit(type, &value))
	{

	}
	else
	{
		SCPI_ErrorPush(context, SCPI_ERROR_INVALID_SUFFIX);
		return SCPI_RES_ERR;
	}

	bsp.config.nominal.type = type;
	bsp.config.nominal.value = value.content.value;


	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalculateLimitNominalQ(scpi_t * context)
{

	SCPI_ResultCharacters(context, nominal_select[bsp.config.nominal.type].name, strlen(nominal_select[bsp.config.nominal.type].name));
	SCPI_ResultDouble(context, bsp.config.nominal.value);

	return SCPI_RES_OK;
}
