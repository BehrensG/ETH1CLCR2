/*
 * scpi_calibration.h
 *
 *  Created on: Nov 20, 2021
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_SCPI_CALIBRATION_H_
#define THIRD_PARTY_BSP_INC_SCPI_CALIBRATION_H_

#include "scpi/scpi.h"

scpi_result_t SCPI_CalibrationADCQ(scpi_t * context);
scpi_result_t SCPI_CalibrationALLQ(scpi_t * context);
scpi_result_t SCPI_CalibrationCountQ(scpi_t * context);
scpi_result_t SCPI_CalibrationDateQ(scpi_t * context);
scpi_result_t SCPI_CalibrationSecureCode(scpi_t * context);
scpi_result_t SCPI_CalibrationSecureState(scpi_t * context);
scpi_result_t SCPI_CalibrationSecureStateQ(scpi_t * context);
scpi_result_t SCPI_CalibrationStore(scpi_t * context);
scpi_result_t SCPI_CalibrationValue(scpi_t * context);

#endif /* THIRD_PARTY_BSP_INC_SCPI_CALIBRATION_H_ */
