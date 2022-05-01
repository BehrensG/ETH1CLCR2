/*
 * scpi_sense.c
 *
 *  Created on: Apr 30, 2022
 *      Author: grzegorz
 */

#include "scpi_sense.h"

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
