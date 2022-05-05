/*
 * scpi_sense.h
 *
 *  Created on: Apr 30, 2022
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_SCPI_SENSE_H_
#define THIRD_PARTY_BSP_INC_SCPI_SENSE_H_

#include "scpi/scpi.h"
#include "bsp.h"


#define MIN_RANGE	1
#define DEF_RANGE	1000
#define MAX_RANGE	100000

scpi_result_t SCPI_SenseFunction(scpi_t * context);
scpi_result_t SCPI_SenseFunctionQ(scpi_t * context);
scpi_result_t SCPI_SenseFImpedanceRangeUpper(scpi_t * context);
scpi_result_t SCPI_SenseFImpedanceRangeUpperQ(scpi_t * context);
#endif /* THIRD_PARTY_BSP_INC_SCPI_SENSE_H_ */
