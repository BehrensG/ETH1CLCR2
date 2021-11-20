/*
 * scpi_measure.h
 *
 *  Created on: Nov 20, 2021
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_INC_SCPI_MEASURE_H_
#define THIRD_PARTY_BSP_INC_SCPI_MEASURE_H_

#include "scpi/scpi.h"

scpi_result_t SCPI_MeasureResultQ(scpi_t * context);
scpi_result_t SCPI_MeasureFrequency(scpi_t * context);
scpi_result_t SCPI_MeasureFrequencyQ(scpi_t * context);
scpi_result_t SCPI_MeasureLevel(scpi_t * context);
scpi_result_t SCPI_MeasureLevelQ(scpi_t * context);
scpi_result_t SCPI_MeasureSpeed(scpi_t * context);
scpi_result_t SCPI_MeasureSpeedQ(scpi_t * context);
scpi_result_t SCPI_MeasureFunction(scpi_t * context);
scpi_result_t SCPI_MeasureFunctionQ(scpi_t * context);
scpi_result_t SCPI_MeasureNominal(scpi_t * context);
scpi_result_t SCPI_MeasureNominalQ(scpi_t * context);
scpi_result_t SCPI_MeasureOutput(scpi_t * context);
scpi_result_t SCPI_MeasureOutputQ(scpi_t * context);

#endif /* THIRD_PARTY_BSP_INC_SCPI_MEASURE_H_ */
