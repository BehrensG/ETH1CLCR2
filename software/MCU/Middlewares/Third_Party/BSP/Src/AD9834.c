/*
 * AD9834.c
 *
 *  Created on: Nov 18, 2021
 *      Author: grzegorz
 */

#include "AD9834.h"

uint16_t reg_config = 0x0000;

extern SPI_HandleTypeDef hspi4;

inline static void SelectChip()
{
	LL_GPIO_ResetOutputPin(SPI4_NSS_GPIO_Port, SPI4_NSS_Pin);
}

inline static void ReleaseChip()
{
	LL_GPIO_SetOutputPin(SPI4_NSS_GPIO_Port, SPI4_NSS_Pin);
}

inline static void SetBit(uint16_t mask) {
  reg_config |= mask;
}

inline static void ClrBit(uint16_t mask) {
  reg_config &= (0xFFFF ^ mask);
}

BSP_StatusTypeDef AD9834_Init()
{
	BSP_StatusTypeDef status = BSP_OK;
	SelectChip();

	SetBit(B28);
//	SetBit(RESET);

	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)reg_config, 1, SPI4_TIMEOUT);
	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)FREQ0_ADDR, 1, SPI4_TIMEOUT);
	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)FREQ0_ADDR, 1, SPI4_TIMEOUT);
	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)FREQ1_ADDR, 1, SPI4_TIMEOUT);
	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)FREQ1_ADDR, 1, SPI4_TIMEOUT);
	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)PHASE0_ADDR, 1, SPI4_TIMEOUT);
	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)PHASE1_ADDR, 1, SPI4_TIMEOUT);

	ReleaseChip();

	return status;
}

BSP_StatusTypeDef AD9834_SetPhase(uint16_t word12)
{
	BSP_StatusTypeDef status = BSP_OK;
	uint16_t tmp = 0;

	word12 &= 0x0FFF;
	tmp = PHASE0_ADDR | word12;
	ClrBit(PSEL);

	SelectChip();

	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)tmp, 1, SPI4_TIMEOUT);
	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)reg_config, 1, SPI4_TIMEOUT);

	ReleaseChip();

	return status;
}

BSP_StatusTypeDef AD9834_SetFrequency(uint32_t freq28)
{
	BSP_StatusTypeDef status = BSP_OK;
	uint16_t msb14 = 0;
	uint16_t lsb14 = 0;

    lsb14 = (uint16_t) (freq28 & 0x3FFF);
    msb14 = (uint16_t) (freq28 >> 14) & 0x3FFF;

    lsb14 |= FREQ0_ADDR;
    msb14 |= FREQ0_ADDR;
    ClrBit(FSEL);

	SelectChip();

	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)lsb14, 1, SPI4_TIMEOUT);
	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)msb14, 1, SPI4_TIMEOUT);
	status = HAL_SPI_Transmit(&hspi4, (uint8_t*)reg_config, 1, SPI4_TIMEOUT);

	ReleaseChip();

	return status;
}
