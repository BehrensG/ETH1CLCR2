/*
 * scpi_calculate.h
 *
 *  Created on: Apr 30, 2022
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_SCPI_CALCULATE_H_
#define THIRD_PARTY_BSP_INC_SCPI_CALCULATE_H_

#include "scpi/scpi.h"
#include "bsp.h"

scpi_result_t SCPI_CalculateFormat(scpi_t * context);
scpi_result_t SCPI_CalculateFormatQ(scpi_t * context);
scpi_result_t SCPI_CalculateLimitNominal(scpi_t * context);
scpi_result_t SCPI_CalculateLimitNominalQ(scpi_t * context);

#endif /* THIRD_PARTY_BSP_INC_SCPI_CALCULATE_H_ */
