#ifndef	_EE24CONFIG_H
#define	_EE24CONFIG_H

#include "main.h"

extern I2C_HandleTypeDef hi2c4;
#define		_EEPROM_SIZE_KBIT			8
#define		_EEPROM_USE_FREERTOS        0
#define		_EEPROM_USE_WP_PIN          0
#define		_EEPROM_I2C   				hi2c4

#define EEPROM_WRITE_DONE 0x44U
#define EEPROM_END 255U

#if (_EEPROM_USE_WP_PIN==1)
#define		_EEPROM_WP_GPIO				EEPROM_WP_GPIO_Port
#define		_EEPROM_WP_PIN				EEPROM_WP_Pin
#endif

#endif

