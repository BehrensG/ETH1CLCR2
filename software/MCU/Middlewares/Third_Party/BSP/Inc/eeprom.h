/*
 * eeprom.h
 *
 *  Created on: Jun 13, 2021
 *      Author: grzegorz
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "main.h"
#include "ee24.h"
#include "bsp.h"

#define EEPROM_ADDRESS 0xA0U
#define EEPROM_SIZE 0xFFU


BSP_StatusTypeDef EEPROM_Erase(void);
BSP_StatusTypeDef EEPROM_Write(bsp_eeprom_union_t *union_data, size_t size);
BSP_StatusTypeDef EEPROM_Read(bsp_eeprom_union_t *union_data, size_t size);
BSP_StatusTypeDef EEPROM_Status(void);


#endif /* INC_EEPROM_H_ */
