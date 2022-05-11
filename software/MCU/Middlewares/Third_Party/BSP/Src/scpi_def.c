/*-
 * Copyright (c) 2012-2013 Jan Breuer,
 *
 * All Rights Reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file   scpi-def.c
 * @date   Thu Nov 15 10:58:45 UTC 2012
 *
 * @brief  SCPI parser test
 *
 *
 */





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scpi_def.h"
#include "scpi/scpi.h"
#include "cmsis_os.h"

#include "scpi_server.h"
#include "scpi_system.h"
#include "scpi_trigger.h"
#include "scpi_format.h"
#include "scpi_calibration.h"
#include "scpi_calculate.h"
#include "scpi_source.h"
#include "scpi_sense.h"
#include "scpi_fetch.h"
#include "scpi_initiate.h"
#include "scpi_read.h"

#include "diff_ampl.h"
#include "bsp.h"
#include "result.h"
#include "DAC7811.h"
#include "DG409.h"
#include "DDS.h"
#include "CS5361.h"
#include "IV_Converter.h"
#include "relays.h"
#include "ADS8681.h"

extern I2S_HandleTypeDef hi2s2;
extern double ADS8681_LSB[];



void resistor_curr_gain_set()
{
	double value = ((bsp.config.voltage/bsp.config.nominal.value)*bsp.config.resistor_value);

	if(value <= 0.015)
	{
		IDiff_Amplifier(IDIFF_GAIN100);
	}
	else if((value> 0.015) && (value <= 0.15))
	{
		IDiff_Amplifier(IDIFF_GAIN10);
	}
	else if(value > 0.15)
	{
		IDiff_Amplifier(IDIFF_GAIN1);
	}

}

void resistor_volt_gain_set()
{
	if(bsp.config.voltage <= 0.015)
	{
		VDiff_Amplifier(VDIFF_GAIN100);
	}
	else if((bsp.config.voltage > 0.015) && (bsp.config.voltage <= 0.15))
	{
		VDiff_Amplifier(VDIFF_GAIN10);
	}
	else if(bsp.config.voltage > 0.15)
	{
		VDiff_Amplifier(VDIFF_GAIN1);
	}

}


size_t SCPI_GetChannels(scpi_t* context, scpi_channel_value_t array[])
{
    scpi_parameter_t channel_list_param;
    // scpi_channel_value_t array[MAXROW * MAXCOL]; /* array which holds values in order (2D) */
    size_t chanlst_idx; /* index for channel list */
    size_t arr_idx = 0; /* index for array */
    size_t n, m = 1; /* counters for row (n) and columns (m) */
    scpi_expr_result_t res;

    /* get channel list */
    if (SCPI_Parameter(context, &channel_list_param, TRUE)) {
        scpi_bool_t is_range;
        int32_t values_from[MAXDIM];
        int32_t values_to[MAXDIM];
        size_t dimensions;

        bool for_stop_row = FALSE; /* true if iteration for rows has to stop */
        bool for_stop_col = FALSE; /* true if iteration for columns has to stop */
        int32_t dir_row = 1; /* direction of counter for rows, +/-1 */
        int32_t dir_col = 1; /* direction of counter for columns, +/-1 */

        /* the next statement is valid usage and it gets only real number of dimensions for the first item (index 0) */
        if (!SCPI_ExprChannelListEntry(context, &channel_list_param, 0, &is_range, NULL, NULL, 0, &dimensions)) {
            chanlst_idx = 0; /* call first index */
            arr_idx = 0; /* set arr_idx to 0 */
            do { /* if valid, iterate over channel_list_param index while res == valid (do-while cause we have to do it once) */
                res = SCPI_ExprChannelListEntry(context, &channel_list_param, chanlst_idx, &is_range, values_from, values_to, 4, &dimensions);
                if (is_range == FALSE) { /* still can have multiple dimensions */
                    if (dimensions == 1) {
                        /* here we have our values
                         * row == values_from[0]
                         * col == 0 (fixed number)
                         * call a function or something */
                        array[arr_idx].row = values_from[0];
                        array[arr_idx].col = 0;
                    } else if (dimensions == 2) {
                        /* here we have our values
                         * row == values_fom[0]
                         * col == values_from[1]
                         * call a function or something */
                        array[arr_idx].row = values_from[0];
                        array[arr_idx].col = values_from[1];
                    } else {
                        return arr_idx = 0;
                    }
                    arr_idx++; /* inkrement array where we want to save our values to, not neccessary otherwise */
                    if (arr_idx >= MAXROW * MAXCOL) {
                        return arr_idx = 0;
                    }
                } else if (is_range == TRUE) {
                    if (values_from[0] > values_to[0]) {
                        dir_row = -1; /* we have to decrement from values_from */
                    } else { /* if (values_from[0] < values_to[0]) */
                        dir_row = +1; /* default, we increment from values_from */
                    }

                    /* iterating over rows, do ilwip nvic gpiot once -> set for_stop_row = false
                     * needed if there is channel list index isn't at end yet */
                    for_stop_row = FALSE;
                    for (n = values_from[0]; for_stop_row == FALSE; n += dir_row) {
                        /* usual case for ranges, 2 dimensions */
                        if (dimensions == 2) {
                            if (values_from[1] > values_to[1]) {
                                dir_col = -1;
                            } else if (values_from[1] < values_to[1]) {
                                dir_col = +1;
                            }
                            /* iterating over columns, do it at least once -> set for_stop_col = false
                             * needed if there is channel list index isn't at end yet */
                            for_stop_col = FALSE;
                            for (m = values_from[1]; for_stop_col == FALSE; m += dir_col) {
                                /* here we have our values
                                 * row == n
                                 * col == m
                                 * call a function or something */
                                array[arr_idx].row = n;
                                array[arr_idx].col = m;
                                arr_idx++;
                                if (arr_idx >= MAXROW * MAXCOL) {
                                    return arr_idx = 0;
                                }
                                if (m == (size_t)values_to[1]) {
                                    /* endpoint reached, stop column for-loop */
                                    for_stop_col = TRUE;
                                }
                            }
                            /* special case for range, example: (@2!1) */
                        } else if (dimensions == 1) {
                            /* here we have values
                             * row == n
                             * col == 0 (fixed number)
                             * call function or sth. */
                            array[arr_idx].row = n;
                            array[arr_idx].col = 0;
                            arr_idx++;
                            if (arr_idx >= MAXROW * MAXCOL) {
                                return arr_idx = 0;
                            }
                        }
                        if (n == (size_t)values_to[0]) {
                            /* endpoint reached, stop row for-loop */
                            for_stop_row = TRUE;
                        }
                    }


                } else {
                    return arr_idx = 0;
                }
                /* increase index */
                chanlst_idx++;
            } while (SCPI_EXPR_OK == SCPI_ExprChannelListEntry(context, &channel_list_param, chanlst_idx, &is_range, values_from, values_to, 4, &dimensions));
            /* while checks, whether incremented index is valid */
        }
        /* do something at the end if needed */
        /* array[arr_idx].row = 0; */
        /* array[arr_idx].col = 0; */
    }
    return arr_idx;
}


static scpi_result_t SCPI_Rst(scpi_t * context)
{

	NVIC_SystemReset();
    return SCPI_RES_OK;
}

static scpi_result_t SCPI_IdnQ(scpi_t * context)
{
	int32_t ptr = 0;
	static char info[46] = {'\0'};

    for (uint8_t i = 0; i < 4; i++)
    {
        if (context->idn[i])
        {
        	ptr += snprintf(info + ptr, sizeof(info) - ptr, "%s,", context->idn[i] );
        }
        else{}
    }

    SCPI_ResultCharacters(context, info, 45);
    return SCPI_RES_OK;
}

scpi_result_t SCPI_TS(scpi_t * context)
{

 	float freq = 100;
	float ampl = 1.28;
	uint32_t atten = 0, vgain = 1, relay = 0;


	if(!SCPI_ParamFloat(context, &freq, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamFloat(context, &ampl, TRUE))
	{
		return SCPI_RES_ERR;
	}
/*
	if(!SCPI_ParamUInt32(context, &atten, TRUE))
	{
		return SCPI_RES_ERR;
	}
*/
	if(!SCPI_ParamUInt32(context, &vgain, TRUE))
	{
		return SCPI_RES_ERR;
	}
	/*
	if(!SCPI_ParamUInt32(context, &igain, TRUE))
	{
		return SCPI_RES_ERR;
	}
*/
	if(!SCPI_ParamUInt32(context, &relay, TRUE))
	{
		return SCPI_RES_ERR;
	}

	DDS_ClockDivider(DDS_DIV0);
	DDS_SetFrequency(freq);
	DAC7811_SetVoltage(ampl);
	DDS_Attenuation(atten);
	TQ2SA_Relays(ADC_SEL, (uint8_t)relay);
	//IV_Converter(R10k);
	VDiff_Amplifier(vgain);
	IDiff_Amplifier(vgain);
	HAL_Delay(10);
	CXN_Relays_AllOn();

	HAL_Delay(10);

	if(relay)
	{
		CS5361_Measure();
	}
	else
	{
		ADS8681_Measurement();
	}


	Result();
// Meas[0] current
// Meas[1] voltage



    return SCPI_RES_OK;
}

const scpi_command_t scpi_commands[] = {
    /* IEEE Mandated Commands (SCPI std V1999.0 4.1.1) */
    { .pattern = "*CLS", .callback = SCPI_CoreCls,},
    { .pattern = "*ESE", .callback = SCPI_CoreEse,},
    { .pattern = "*ESE?", .callback = SCPI_CoreEseQ,},
    { .pattern = "*ESR?", .callback = SCPI_CoreEsrQ,},
    { .pattern = "*IDN?", .callback = SCPI_IdnQ,},
    { .pattern = "*OPC", .callback = SCPI_CoreOpc,},
    { .pattern = "*OPC?", .callback = SCPI_CoreOpcQ,},
    { .pattern = "*RST", .callback = SCPI_Rst,},
    { .pattern = "*SRE", .callback = SCPI_CoreSre,},
    { .pattern = "*SRE?", .callback = SCPI_CoreSreQ,},
    { .pattern = "*STB?", .callback = SCPI_CoreStbQ,},
    { .pattern = "*TST?", .callback = SCPI_CoreTstQ,},
    { .pattern = "*WAI", .callback = SCPI_CoreWai,},

    {.pattern = "STATus:QUEStionable[:EVENt]?", .callback = SCPI_StatusQuestionableEventQ,},
    /* {.pattern = "STATus:QUEStionable:CONDition?", .callback = scpi_stub_callback,}, */
    {.pattern = "STATus:QUEStionable:ENABle", .callback = SCPI_StatusQuestionableEnable,},
    {.pattern = "STATus:QUEStionable:ENABle?", .callback = SCPI_StatusQuestionableEnableQ,},

    {.pattern = "STATus:PRESet", .callback = SCPI_StatusPreset,},

    /* Required SCPI commands (SCPI std V1999.0 4.2.1) */
    {.pattern = "SYSTem:ERRor[:NEXT]?", .callback = SCPI_SystemErrorNextQ,},
    {.pattern = "SYSTem:ERRor:COUNt?", .callback = SCPI_SystemErrorCountQ,},
    {.pattern = "SYSTem:VERSion?", .callback = SCPI_SystemVersionQ,},

	{.pattern = "SYSTem:COMMunicate:LAN:IPADdress", .callback = SCPI_SystemCommunicateLANIPAddress,},
	{.pattern = "SYSTem:COMMunicate:LAN:IPADdress?", .callback = SCPI_SystemCommunicateLANIPAddressQ,},
	{.pattern = "SYSTem:COMMunicate:LAN:SMASk", .callback = SCPI_SystemCommunicateLANIPSmask,},
	{.pattern = "SYSTem:COMMunicate:LAN:SMASk?", .callback = SCPI_SystemCommunicateLANIPSmaskQ,},
	{.pattern = "SYSTem:COMMunicate:LAN:GATEway", .callback = SCPI_SystemCommunicateLANGateway,},
	{.pattern = "SYSTem:COMMunicate:LAN:GATEway?", .callback = SCPI_SystemCommunicateLANGatewayQ,},
	{.pattern = "SYSTem:COMMunicate:LAN:MAC", .callback = SCPI_SystemCommunicateLANMAC,},
	{.pattern = "SYSTem:COMMunicate:LAN:MAC?", .callback = SCPI_SystemCommunicateLANMACQ,},
	{.pattern = "SYSTem:COMMunicate:LAN:PORT", .callback = SCPI_SystemCommunicateLANPort,},
	{.pattern = "SYSTem:COMMunicate:LAN:PORT?", .callback = SCPI_SystemCommunicateLANPortQ,},
	{.pattern = "SYSTem:COMMunication:LAN:UPDate", .callback = SCPI_SystemCommunicationLanUpdate,},
	{.pattern = "SYSTem:SERVice:EEPROM", .callback = SCPI_SystemServiceEEPROM,},
	{.pattern = "SYSTem:SERVice:ID", .callback = SCPI_SystemServiceID,},
	{.pattern = "SYSTem:SECure:STATe", .callback = SCPI_SystemSecureState,},
	{.pattern = "SYSTem:SECure:STATe?", .callback = SCPI_SystemSecureStateQ,},
	{.pattern = "SYSTem:TEMPerature?", .callback = SCPI_SystemTemperatureQ,},
	{.pattern = "SYSTem:TEMPerature:UNIT", .callback = SCPI_SystemTemperatureUnit,},
	{.pattern = "SYSTem:TEMPerature:UNIT?", .callback = SCPI_SystemTemperatureUnitQ,},
	{.pattern = "SYSTem:HUMIdity?", .callback = SCPI_SystemHumidityQ,},

	{.pattern = "TRIGger:DELay", .callback = SCPI_TriggerDelay,},
	{.pattern = "TRIGger:DELay?", .callback = SCPI_TriggerDelayQ,},
	{.pattern = "TRIGger[:IMMediate]", .callback = SCPI_TriggerImmediate,},
	{.pattern = "TRIGger:SOURce", .callback = SCPI_TriggerSource,},
	{.pattern = "TRIGger:SOURce?", .callback = SCPI_TriggerSourceQ,},
	{.pattern = "TRIGger:SLOPe", .callback = SCPI_TriggerSlope,},
	{.pattern = "TRIGger:SLOPe?", .callback = SCPI_TriggerSlopeQ,},
	{.pattern = "OUTput:TRIGger", .callback = SCPI_TriggerOutput,},
	{.pattern = "OUTput:TRIGger:SLOPe", .callback = SCPI_TriggerOutputSlope,},
	{.pattern = "OUTput:TRIGger:SLOPe?", .callback = SCPI_TriggerOutputSlopeQ,},
	{.pattern = "*TRG", .callback = SCPI_TRG,},

	{.pattern = "FORMat[:DATA]", .callback = SCPI_FormatData,},
	{.pattern = "FORMat[:DATA]?", .callback = SCPI_FormatDataQ,},

	{.pattern = "CALibration:ADC?", .callback = SCPI_CalibrationADCQ,},
	{.pattern = "CALibration[:ALL]?", .callback = SCPI_CalibrationALLQ,},
	{.pattern = "CALibration:COUNt?", .callback = SCPI_CalibrationCountQ,},
	{.pattern = "CALibration:DATE?", .callback = SCPI_CalibrationDateQ,},
	{.pattern = "CALibration:SECure:CODE", .callback = SCPI_CalibrationSecureCode,},
	{.pattern = "CALibration:SECure:STATe", .callback = SCPI_CalibrationSecureState,},
	{.pattern = "CALibration:STORe", .callback = SCPI_CalibrationStore,},
	{.pattern = "CALibration:VALue", .callback = SCPI_CalibrationValue,},

	{.pattern = "SOURce:FREQuency[:CW]", .callback = SCPI_SourceFrequency,},
	{.pattern = "SOURce:FREQuency?", .callback = SCPI_SourceFrequencyQ,},
	{.pattern = "SOURce:VOLTage[:AMPLitude]", .callback = SCPI_SourceVoltage,},
	{.pattern = "SOURce:VOLTage?", .callback = SCPI_SourceVoltageQ,},
	{.pattern = "SOURce:VOLTage?", .callback = SCPI_SourceVoltageQ,},
	{.pattern = "SOURce:RELAy:OUTput", .callback = SCPI_SourceRelayOutput,},
	{.pattern = "SOURce:RELAy:OUTput?", .callback = SCPI_SourceRelayOutputQ,},

	{.pattern = "[SENSe]:FUNCtion[:ON]", .callback = SCPI_SenseFunction,},
	{.pattern = "[SENSe]:FUNCtion[:ON]?", .callback = SCPI_SenseFunctionQ,},
	{.pattern = "[SENSe]:FIMPedance:RANGe[:UPPer]", .callback = SCPI_SenseFImpedanceRangeUpper,},
	{.pattern = "[SENSe]:FIMPedance:RANGe[:UPPer]?", .callback = SCPI_SenseFImpedanceRangeUpperQ,},

	{.pattern = "[SENSe]:CORRection:COLLect[:ACQuire]", .callback = SCPI_SenseCorrectionCollectAcquire,},
	{.pattern = "[SENSe]:CORRection:COLLect[:ACQuire]?", .callback = SCPI_SenseCorrectionCollectAcquireQ,},
	{.pattern = "[SENSe]:CORRection:STATe", .callback = SCPI_SenseCorrectionState,},
	{.pattern = "[SENSe]:CORRection:STATe?", .callback = SCPI_SenseCorrectionStateQ,},

	{.pattern = "CALCulate:FORMat", .callback = SCPI_CalculateFormat,},
	{.pattern = "CALCulate:FORMat?", .callback = SCPI_CalculateFormatQ,},
	{.pattern = "CALCulate:LIMit:NOMinal", .callback = SCPI_CalculateLimitNominal,},
	{.pattern = "CALCulate:LIMit:NOMinal?", .callback = SCPI_CalculateLimitNominalQ,},

	{.pattern = "READ?", .callback = SCPI_ReadQ,},

	{.pattern = "FETCh?", .callback = SCPI_FetchQ,},

	{.pattern = "INITiate[:IMMediate]", .callback = SCPI_Initiate,},

	{.pattern = "TS", .callback = SCPI_TS,},
		SCPI_CMD_LIST_END
};

scpi_interface_t scpi_interface = {
    .error = SCPI_Error,
    .write = SCPI_Write,
    .control = SCPI_Control,
    .flush = SCPI_Flush,
    .reset = SCPI_Reset,
};

char scpi_input_buffer[SCPI_INPUT_BUFFER_LENGTH];
scpi_error_t scpi_error_queue_data[SCPI_ERROR_QUEUE_SIZE];

scpi_t scpi_context;
