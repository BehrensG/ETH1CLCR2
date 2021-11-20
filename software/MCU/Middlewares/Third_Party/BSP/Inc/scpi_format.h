/*
 * scpi_format.h
 *
 *  Created on: Nov 20, 2021
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_SCPI_FORMAT_H_
#define THIRD_PARTY_BSP_INC_SCPI_FORMAT_H_

#include "scpi/scpi.h"

scpi_result_t SCPI_FormatData(scpi_t * context);
scpi_result_t SCPI_FormatDataQ(scpi_t * context);

#endif /* THIRD_PARTY_BSP_INC_SCPI_FORMAT_H_ */
