/*
 * scpi_initiate.c
 *
 *  Created on: May 1, 2022
 *      Author: grzegorz
 */

#include "diff_ampl.h"
#include "scpi_initiate.h"
#include "ADS8681.h"
#include "result.h"
#include "scpi_def.h"

scpi_result_t SCPI_Initiate(scpi_t * context)
{
	switch(bsp.config.nominal.type)
	{
		case NONE: ;break;
		case R: {resistor_volt_gain_set(); resistor_curr_gain_set();}; break;
		case C: ;break;
		case L: ;break;
	}

	ADS8681_Measurement();
	Result();

	return SCPI_RES_OK;
}
