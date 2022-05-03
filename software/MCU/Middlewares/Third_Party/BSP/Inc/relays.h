/*
 * relays.h
 *
 *  Created on: Nov 14, 2021
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_RELAYS_H_
#define THIRD_PARTY_BSP_INC_RELAYS_H_

#include "bsp.h"

/*************************************** TQ2SA ***************************************/

#define IRR0 	1
#define VDIFF0 	2
#define ADC_SEL	3

/*********************************** SN74LVC1G3157 ************************************/

#define IDIFF0	1
#define IDIFF1	2
#define VDIFF1	3
#define VDIFF2	4

#define B1 0
#define B2 1

/************************************** DG409DY ***************************************/

#define S1A	1
#define S2A	2
#define S3A	3
#define S4A	4

/************************************* Functions **************************************/

void CXN_Relays_AllOn(void);
void CXN_Relays_AllOff(void);
void TQ2SA_Relays(uint8_t relay, uint8_t state);
void SN74LVC1G3157_AnalogSwitch(uint8_t analog_switch, uint8_t b_state);
void DG409_AnalogSwitch(uint8_t analog_switch);
void CXN_Relays_Control(int32_t relay, uint8_t state);

#endif /* THIRD_PARTY_BSP_INC_RELAYS_H_ */
