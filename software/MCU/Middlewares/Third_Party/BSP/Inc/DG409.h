/*
 * DG409.h
 *
 *  Created on: Feb 20, 2022
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_DG409_H_
#define THIRD_PARTY_BSP_INC_DG409_H_

#include "bsp.h"

typedef enum
{
	DG409_S1A		= 1U,
	DG409_S2A		= 2U,
	DG409_S3A		= 3U,
	DG409_S4A		= 4U
} dg409_channel_e;


void DG409_MUX(dg409_channel_e channel);

#endif /* THIRD_PARTY_BSP_INC_DG409_H_ */
