/*
 * CS5361.h
 *
 *  Created on: Mar 5, 2022
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_CS5361_H_
#define THIRD_PARTY_BSP_INC_CS5361_H_

#include "bsp.h"

#define CS5361_VOLT_RES (double)(2.5/16777216)

typedef enum
{
	CS5361_SIGNLE_SPEED = 0,
	CS5361_DOUBLE_SPEED,
	CS5361_QUAD_SPEED
}e_sample_rate_t;

void CS5361_nReset(uint8_t state);
void CS5361_ModeSelect(uint8_t mode);
void CS5361_nHighPassFilter(uint8_t state);
void CS5361_MCLKDivider(uint8_t state);
void CS5361_SampleRate(e_sample_rate_t rate);
void CS5361_Init();

#endif /* THIRD_PARTY_BSP_INC_CS5361_H_ */
