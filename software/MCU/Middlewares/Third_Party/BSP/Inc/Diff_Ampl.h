/*
 * Diff_Ampl.h
 *
 *  Created on: Mar 5, 2022
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_DIFF_AMPL_H_
#define THIRD_PARTY_BSP_INC_DIFF_AMPL_H_

#include "bsp.h"

typedef enum
{
	VDIFF_GAIN2 = 		0,
	VDIFF_GAIN20 = 		1,
	VDIFF_GAIN200 = 	2,
	VDIFF_GAIN2000 = 	3
}e_vdiff;

typedef enum
{
	IDIFF_GAIN2 = 		0,
	IDIFF_GAIN20 = 		1,
	IDIFF_GAIN200 = 	2
}e_idiff;

void VDiff_Amplifier(e_vdiff gain);
void IDiff_Amplifier(e_idiff gain);

#endif /* THIRD_PARTY_BSP_INC_DIFF_AMPL_H_ */
