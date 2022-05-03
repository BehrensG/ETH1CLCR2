/*
 * scpi_measure.h
 *
 *  Created on: Nov 20, 2021
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_SCPI_SOURCE_H_
#define THIRD_PARTY_BSP_INC_SCPI_SOURCE_H_

#include "scpi/scpi.h"
#include "bsp.h"

#define MIN_FREQ	20
#define DEF_FREQ	1000
#define MAX_FREQ	10000

#define MIN_VOLT	0.010
#define DEF_VOLT	0.1
#define MAX_VOLT	1.5

scpi_result_t SCPI_SourceFrequency(scpi_t * context);
scpi_result_t SCPI_SourceFrequencyQ(scpi_t * context);
scpi_result_t SCPI_SourceVoltage(scpi_t * context);
scpi_result_t SCPI_SourceVoltageQ(scpi_t * context);
scpi_result_t SCPI_SourceRelayOutput(scpi_t * context);
scpi_result_t SCPI_SourceRelayOutputQ(scpi_t * context);

#endif /* THIRD_PARTY_BSP_INC_SCPI_SOURCE_H_ */
