/*
 * IV_Converter.h
 *
 *  Created on: Mar 12, 2022
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_IV_CONVERTER_H_
#define THIRD_PARTY_BSP_INC_IV_CONVERTER_H_

#include "bsp.h"

#define R1		1
#define R100	2
#define R1k		3
#define R10k	4
#define R100k 	5

void IV_Converter(uint8_t resistor);

#endif /* THIRD_PARTY_BSP_INC_IV_CONVERTER_H_ */
