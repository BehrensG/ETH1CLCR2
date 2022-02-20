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
	DG409_SA1		= 1U,
	DG409_SA2		= 2U,
	DG409_SA3		= 3U,
	DG409_SA4		= 4U
} dg409_channel_e;


void DG409_MUX(dg409_channel_e channel);

#endif /* THIRD_PARTY_BSP_INC_DG409_H_ */
