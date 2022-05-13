/*
 * scpi_calibration.c
 *
 *  Created on: Nov 20, 2021
 *      Author: grzegorz
 */

#include "scpi_calibration.h"
#include "bsp.h"

scpi_choice_def_t calib_state_select[] =
{
    {"OFF", 0},
    {"ON", 1},
	{"0", 0},
	{"1", 1},
    SCPI_CHOICE_LIST_END
};


scpi_result_t SCPI_CalibrationADCQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationALLQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationCountQ(scpi_t * context)
{
	char buffer[6] = {0};

	snprintf(buffer,sizeof(buffer), "%d", bsp.eeprom.structure.calibration_count);
	SCPI_ResultCharacters(context, buffer, strlen(buffer));

	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationDateQ(scpi_t * context)
{
	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationSecureCode(scpi_t * context)
{
	char string[PASSWORD_LENGTH];
	size_t len = 0;

	if(bsp.calibration.status)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_CALIBRATION_MEMORY_SECURE);
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamCopyText(context, (char*)string, PASSWORD_LENGTH, &len, TRUE))
	{
		return SCPI_RES_ERR;
	}

	strncpy(bsp.eeprom.structure.calib_password, string, PASSWORD_LENGTH);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_CalibrationSecureState(scpi_t * context)
{
	int32_t state = 1;
	int8_t password_read[PASSWORD_LENGTH] = {0};
	size_t length = 0;
	int8_t* password_reference = bsp.eeprom.structure.calib_password;

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
	size_t channel_size = 0;
	uint8_t index = 0;


	if(bsp.calibration.status)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_CALIBRATION_MEMORY_SECURE);
		return SCPI_RES_ERR;
	}

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
