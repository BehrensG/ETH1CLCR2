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
#include "bsp.h"
#include "cmsis_os.h"

#include "scpi_server.h"
#include "scpi_system.h"
#include "scpi_measure.h"
#include "scpi_trigger.h"
#include "scpi_format.h"
#include "scpi_calibration.h"

#include "DAC7811.h"
#include "DG409.h"
#include "DDS.h"
#include "CS5361.h"
#include "IV_Converter.h"
#include "Diff_Ampl.h"
#include "relays.h"
#include "ADS8681.h"

extern I2S_HandleTypeDef hi2s2;

__attribute__((section(".RAM_D1"))) float meas[2][2000];


extern double ADS8681_LSB[];

static scpi_result_t TEST_TSQ(scpi_t * context)
{

	return SCPI_RES_OK;
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
	float ampl = 1.28, tmp[2];
	uint32_t atten = 0, vgain = 1, igain = 1, relay = 0;
	uint16_t tx_data[2];
	HAL_StatusTypeDef status;
	__IO int32_t tx_meas[250];
	double volts[250];
	int test[10];

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

	if(!SCPI_ParamUInt32(context, &vgain, TRUE))
	{
		return SCPI_RES_ERR;
	}

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
	IV_Converter(R10k);
	VDiff_Amplifier(vgain);
	IDiff_Amplifier(igain);
	HAL_Delay(10);
	CXN_Relays_AllOn();

	HAL_Delay(10);

	status = HAL_I2S_Receive(&hi2s2, tx_meas, 250, 10000);

	for(uint16_t x=0; x < 250; x++)
	{
		if(tx_meas[x] & 0x800000)
		{
			tx_meas[x] |= 0xFF000000;
		}
		volts[x] = (double)(tx_meas[x]*CS5361_VOLT_RES);
	}


 	for (uint16_t x=0; x < 2000;x++)
	{
		ADS8681_RawData(tx_data);

		tmp[0] = tx_data[0] - ADS8681_FSR_CENTER;
		tmp[1] = tx_data[1] - ADS8681_FSR_CENTER;
		meas[0][x] = (float)(tmp[0]*ADS8681_LSB[bsp.adc_ads8681[0].range]) - 0.023;
		meas[1][x] = (float)(tmp[1]*ADS8681_LSB[bsp.adc_ads8681[1].range]) - 0.023;
	}


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

	{.pattern = "MEASure:RESult?", .callback = SCPI_MeasureResultQ,},
	{.pattern = "MEASure:FREQuency", .callback = SCPI_MeasureFrequency,},
	{.pattern = "MEASure:FREQuency?", .callback = SCPI_MeasureFrequencyQ,},
	{.pattern = "MEASure:LEVel", .callback = SCPI_MeasureLevel,},
	{.pattern = "MEASure:LEVel?", .callback = SCPI_MeasureLevelQ,},
	{.pattern = "MEASure:SPEED", .callback = SCPI_MeasureSpeed,},
	{.pattern = "MEASure:SPEED?", .callback = SCPI_MeasureSpeedQ,},
	{.pattern = "MEASure:FUNCtion", .callback = SCPI_MeasureFunction,},
	{.pattern = "MEASure:FUNCtion?", .callback = SCPI_MeasureFunctionQ,},
	{.pattern = "MEASure:NOMinal", .callback = SCPI_MeasureNominal,},
	{.pattern = "MEASure:NOMinal?", .callback = SCPI_MeasureNominalQ,},
	{.pattern = "MEASure:OUTput", .callback = SCPI_MeasureOutput,},
	{.pattern = "MEASure:OUTput?", .callback = SCPI_MeasureOutputQ,},

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
