/*
 * DDS.h
 *
 *  Created on: Nov 17, 2021
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_DDS_H_
#define THIRD_PARTY_BSP_INC_DDS_H_

typedef enum
{
	DDS_DIV0		= 0U,
	DDS_DIV2		= 2U,
	DDS_DIV4		= 4U,
	DDS_DIV8		= 8U,
	DDS_DIV10		= 10U
} dds_clk_div_e;

#define DDS_DIV0_RES	0.0610351f
#define DDS_DIV2_RES	0.0305176f
#define DDS_DIV4_RES	0.0203438f
#define DDS_DIV8_RES	0.0122070f
#define DDS_DIV10_RES	0.0012207f

void DDS_SetFrequency(float freq);

#endif /* THIRD_PARTY_BSP_INC_DDS_H_ */
