/*
 * scpi_calculate.c
 *
 *  Created on: Apr 30, 2022
 *      Author: grzegorz
 */

#include "scpi_calculate.h"

scpi_choice_def_t Calculation_select[] =
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
    SCPI_CHOICE_LIST_END
};

scpi_result_t SCPI_CalculateFormat(scpi_t * context)
{
	int32_t format1 = NONE, format2 = NONE;

	if(!SCPI_ParamChoice(context, Calculation_select, &format1, TRUE))
	{
		return SCPI_RES_ERR;
	}


	if(!SCPI_ParamChoice(context, Calculation_select, &format2, FALSE))
	{
		return SCPI_RES_ERR;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalculateFormatQ(scpi_t * context)
{
	SCPI_ResultCharacters(context, Calculation_select[bsp.config.format1].name, strlen(Calculation_select[bsp.config.format1].name));
	SCPI_ResultCharacters(context, Calculation_select[bsp.config.format2].name, strlen(Calculation_select[bsp.config.format2].name));
	return SCPI_RES_OK;
}
