/*
 * HE3621A.h
 *
 *  Created on: Feb 20, 2022
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_HE3621A_H_
#define THIRD_PARTY_BSP_INC_HE3621A_H_

#include "bsp.h"

typedef enum
{
 	HE3621A_H_CUR = 0x00,
	HE3621A_L_CUR = 0x01,
	HE3621A_GND_C = 0x02,
	HE3621A_GND_D = 0x04,
	HE3621A_H_POT = 0x08,
	HE3621A_L_POT = 0x10,
}he3621a_mux_e;

#define HE3621_REL_COUNT 6

void HE3621A_Mux(he3621a_mux_e relay, uint8_t state);
void HE3621A_Mux_AllOn();
void HE3621A_Mux_AllOff();

#endif /* THIRD_PARTY_BSP_INC_HE3621A_H_ */
