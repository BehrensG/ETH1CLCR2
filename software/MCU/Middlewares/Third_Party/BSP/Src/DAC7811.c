/*
 * DAC7811.c
 *
 *  Created on: Feb 19, 2022
 *      Author: grzegorz
 */


#include "bsp.h"
#include "DAC7811.h"

extern SPI_HandleTypeDef hspi5;

inline static void SelectChip()
{
	LL_GPIO_ResetOutputPin(SPI5_NSS_GPIO_Port, SPI5_NSS_Pin);
}

inline static void ReleaseChip()
{
	LL_GPIO_SetOutputPin(SPI5_NSS_GPIO_Port, SPI5_NSS_Pin);
}


BSP_StatusTypeDef DAC7811_SetVoltage(float voltage)
{
	uint16_t code[1] = {0};

	BSP_StatusTypeDef status = BSP_OK;
	code[0] = (uint16_t)((voltage/DDS_AMP)*4095);
	code[0] = (code[0] & 0x8FFF) | DAC7811_UPDATE;

	SelectChip();
	status = HAL_SPI_Transmit(&hspi5, (uint8_t*)code, 1, SPI_DELAY);
	ReleaseChip();

	return status;
}
