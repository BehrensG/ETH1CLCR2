/*
 * calculate.h
 *
 *  Created on: Apr 12, 2022
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_CALCULATE_H_
#define THIRD_PARTY_BSP_INC_CALCULATE_H_

#include "bsp.h"


#define PI 3.141592654

#define SIN_LUT_LEN 4000    //it's only from 0 to pi/4
#define SIN_LUT_PARTS 8     //LUT divided to few to be able to push into uC memory



void Calculate();

#endif /* THIRD_PARTY_BSP_INC_CALCULATE_H_ */
