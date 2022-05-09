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
	VDIFF_GAIN1 = 		1,
	VDIFF_GAIN10 = 		10,
	VDIFF_GAIN100 = 	100,
	VDIFF_GAIN1000 = 	1000
}e_vdiff;

typedef enum
{
	IDIFF_GAIN1 = 		1,
	IDIFF_GAIN10 = 		10,
	IDIFF_GAIN100 = 	100
}e_idiff;

void VDiff_Amplifier(e_vdiff gain);
void IDiff_Amplifier(e_idiff gain);

#endif /* THIRD_PARTY_BSP_INC_DIFF_AMPL_H_ */
