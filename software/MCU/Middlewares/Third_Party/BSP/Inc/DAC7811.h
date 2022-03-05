/*
 * DAC7811.h
 *
 *  Created on: Feb 19, 2022
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_DAC7811_H_
#define THIRD_PARTY_BSP_INC_DAC7811_H_

#include "bsp.h"

#define DAC7811_UPDATE		(0x1 << 12)
#define DDS_AMP				3.46


BSP_StatusTypeDef DAC7811_SetVoltage(float voltage);

#endif /* THIRD_PARTY_BSP_INC_DAC7811_H_ */
