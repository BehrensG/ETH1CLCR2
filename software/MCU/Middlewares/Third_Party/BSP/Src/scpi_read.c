/*
 * scpi_read.c
 *
 *  Created on: May 9, 2022
 *      Author: grzegorz
 */

#include "scpi_read.h"
#include "ADS8681.h"
#include "result.h"
#include "scpi_def.h"

scpi_result_t SCPI_ReadQ(scpi_t * context)
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


	if(FIMP == bsp.config.function)
	{
		switch(bsp.config.format1)
		{
			case NONE: /* Do nothing */ ; break;
			case MLIN: SCPI_ResultDouble(context, bsp.result.MLIN); break;
			case REAL: SCPI_ResultDouble(context, bsp.result.REAL); break;
			case CS: SCPI_ResultDouble(context, bsp.result.CS); break;
			case LS: SCPI_ResultDouble(context, bsp.result.LS); break;
		}
		switch(bsp.config.format2)
		{
			case NONE: /* Do nothing */ ; break;
			case PHAS: SCPI_ResultFloat(context, bsp.result.PHAS); break;
			case IMAG: SCPI_ResultFloat(context, bsp.result.IMAG); break;
			case D: SCPI_ResultFloat(context, bsp.result.D); break;
			case Q: SCPI_ResultFloat(context, bsp.result.Q); break;
			case REAL: SCPI_ResultFloat(context, bsp.result.REAL); break;
		}
	}
	else if(FADM == bsp.config.function)
	{
		switch(bsp.config.format1)
		{
			case NONE: /* Do nothing */ ; break;
			case MLIN: SCPI_ResultFloat(context, bsp.result.Y); break;
			case REAL: SCPI_ResultFloat(context, bsp.result.G); break;
			case CP: SCPI_ResultFloat(context, bsp.result.CP); break;
			case LP: SCPI_ResultFloat(context, bsp.result.LP); break;
		}
		switch(bsp.config.format2)
		{
			case NONE: /* Do nothing */ ; break;
			case PHAS: SCPI_ResultFloat(context, bsp.result.PHAS); break;
			case IMAG: SCPI_ResultFloat(context, bsp.result.B); break;
			case D: SCPI_ResultFloat(context, bsp.result.D); break;
			case Q: SCPI_ResultFloat(context, bsp.result.Q); break;
			case REAL: SCPI_ResultFloat(context, bsp.result.REAL); break;
			case RP: SCPI_ResultFloat(context, bsp.result.RP); break;
		}
	}

	return SCPI_RES_OK;
}
