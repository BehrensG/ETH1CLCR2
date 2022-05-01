/*
 * bsp.h
 *
 *  Created on: Nov 13, 2021
 *      Author: grzegorz
 */

#ifndef THIRD_PARTY_BSP_BSP_H_
#define THIRD_PARTY_BSP_BSP_H_

#include "main.h"

/*************************************** COMMON ***************************************/

#define ON 1
#define OFF 0


/*************************************** SCPI ***************************************/

#define SCPI_MANUFACTURER_STRING_LENGTH 16
#define SCPI_DEVICE_STRING_LENGTH 16
#define SCPI_SERIALNUMBER_STRING_LENGTH 16
#define SCPI_SOFTWAREVERSION_STRING_LENGTH 16
#define HOSTNAME_LENGTH 20
#define PASSWORD_LENGTH 16
#define PASSWORD "ETH1LCR2"

/*************************************** ETHERNET ***************************************/

#define IP_ADDRESS_0 192
#define IP_ADDRESS_1 168
#define IP_ADDRESS_2 0
#define IP_ADDRESS_3 126

#define NETMASK_ADDRESS_0 255
#define NETMASK_ADDRESS_1 255
#define NETMASK_ADDRESS_2 255
#define NETMASK_ADDRESS_3 0

#define GATEWAY_ADDRESS_0 192
#define GATEWAY_ADDRESS_1 168
#define GATEWAY_ADDRESS_2 0
#define GATEWAY_ADDRESS_3 1

#define MAC_0 0x00
#define MAC_1 0x80
#define MAC_2 0xE1
#define MAC_3 0x00
#define MAC_4 0x00
#define MAC_5 0x00

#define TCPIP_DEFAULT_PORT 2000

#define VOLTAGE_INDEX 0
#define CURRENT_INDEX 1

#define WAV_LEN_MAX 512
#define ADC_CS5361	1
#define ADC_ADS8681	0

#define NONE 0

enum function_select
{
	FIMP	= 1U,
	FADM	= 2U,
};

enum calc_function
{
	REAL	= 1U,
	IMAG	= 2U,
	MLIN	= 3U,
	PHAS	= 4U,
	CP		= 5U,
	CS		= 6U,
	LP		= 7U,
	LS		= 8U,
	D		= 9U,
	Q		= 10U,
	RP		= 11U
};

/*************************************** MCU ***************************************/

#define MCU_SERVICE_SECURITY_OFF 0
#define MCU_SERVICE_SECURITY_ON 1

/*************************************** I2C EEPROM ***************************************/

/*************************************** SPI ***************************************/

#define SPI_MAX_DELAY 	20000
#define SPI_DELAY 		1000


/*************************************** MCU ***************************************/


#define delayUS_ASM(us) do {\
	asm volatile (	"MOV R0,%[loops]\n\t"\
			"1: \n\t"\
			"SUB R0, #1\n\t"\
			"CMP R0, #0\n\t"\
			"BNE 1b \n\t" : : [loops] "r" (320*us) : "memory"\
		      );\
} while(0)

#define delay100NS_ASM(ns) do {\
	asm volatile (	"MOV R0,%[loops]\n\t"\
			"1: \n\t"\
			"SUB R0, #1\n\t"\
			"CMP R0, #0\n\t"\
			"BNE 1b \n\t" : : [loops] "r" (24*ns) : "memory"\
		      );\
} while(0)

typedef enum
{
  BSP_OK       				= 0x00U,
  BSP_ERROR    				= 0x01U,
  BSP_BUSY     				= 0x02U,
  BSP_TIMEOUT  				= 0x03U,
  BSP_ADC_CONFIG_ERROR 		= 0x04U,
  BSP_EEPROM_EMPTY 			= 0x05U,
  BSP_EEPROM_MAX_SIZE 		= 0x06U,
  BSP_EEPROM_NO_CONNECTION 	= 0x07U,
  BSP_EEPROM_WRITE_ERROR 	= 0x08U,
  BSP_EEPROM_READ_ERROR 	= 0x09U,
  BSP_MODULE_MISSING		= 0x0AU
} BSP_StatusTypeDef;


#define MCU_SERVICE_SECURITY_OFF 0
#define MCU_SERVICE_SECURITY_ON 1

#define EEPROM_CFG_SIZE 229


#define SAMPLE_TIMER_MAX 1000000
#define SAMPLE_TIMER_MIN 1
#define SAMPLE_TIMER_DEF 1000



#pragma pack(push, 1)

// size 64
typedef struct bsp_scpi_info
{
	char manufacturer[SCPI_MANUFACTURER_STRING_LENGTH];
	char device[SCPI_DEVICE_STRING_LENGTH];
	char serial_number[SCPI_SERIALNUMBER_STRING_LENGTH];
	char software_version[SCPI_SOFTWAREVERSION_STRING_LENGTH];

}bsp_scpi_info_t;


// size 20
typedef struct bsp_ip4_lan
{
	uint8_t ip[4];
	uint8_t netmask[4];
	uint8_t gateway[4];
	uint8_t MAC[6];
	uint16_t port;

}bsp_ip4_lan_t;


typedef struct bsp_adc_calib_ads8681
{
	double gain_1;
	double gain_10;
	double gain_100;

}bsp_adc_calib_ads8681_t;

typedef struct bsp_adc_calib_cs5361
{
	double gain[3];

}bsp_adc_calib_cs5361_t;

typedef struct bsp_calibration_date
{
	uint8_t day;
	uint8_t month;
	uint16_t year;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;

}bsp_calibration_date_t;

typedef union bsp_eeprom_union
{
	struct data
	{
		// Size 20
		bsp_ip4_lan_t ip4;
		// Size 64
		bsp_scpi_info_t info;
		// Size 48
		bsp_adc_calib_ads8681_t adc_calib_ads8681[2];
		// Size 48
		bsp_adc_calib_cs5361_t adc_calib_cs5361[2];
		// Size 19
		int8_t service_password[PASSWORD_LENGTH];
		// Size 19
		int8_t calib_password[PASSWORD_LENGTH];
		// Size 7
		bsp_calibration_date_t calib_date;
		// Size 4
		uint32_t calibration_count;

	}structure;
	uint8_t bytes[EEPROM_CFG_SIZE];

}bsp_eeprom_union_t;

#pragma pack(pop)



typedef struct bsp_result_voltage
{
	double wave[WAV_LEN_MAX];

}bsp_result_voltage_t;

typedef struct bsp_result_current
{
    double wave[WAV_LEN_MAX];

}bsp_result_current_t;

typedef struct bsp_result
{
    double volt_real;
    double volt_imag;
    double curr_real;
    double curr_imag;
    double z_real;
    double z_imag;
    double y_real;
    double y_imag;

    double REAL;
    double IMAG;
    double MLIN;
    double CP;
    double CS;
    double LP;
    double LS;
    double PHAS;
    double D;
    double Q;
    double RP;

}bsp_result_t;

// size 17
typedef struct bsp_security
{
	uint8_t status;

}bsp_security_t;

typedef struct bsp_calibration
{
	uint8_t status;

}bsp_calibration_t;

typedef struct bsp_trigger
{

	uint8_t in_slope;
	uint8_t out_slope;
	uint32_t delay;
	uint8_t source;
	uint32_t count;

}bsp_trigger_t;

typedef struct bsp_temperature
{
	uint8_t unit;

}bsp_temperature_t;


typedef struct bsp_adc_ads8681
{
	float zero_offset;
	uint8_t range;
}bsp_adc_ads8681_t;

typedef struct bsp_measure
{
	bsp_result_t result;
    bsp_result_current_t current;
    bsp_result_voltage_t voltage;

}bsp_measure_t;

typedef struct ads8681_cfg
{
	int32_t delay;
	uint32_t sample_size;
}ads8681_cfg_t;

typedef struct bsp_config
{
	float frequency;
	float voltage;
	uint16_t volt_gain;
	uint8_t volt_gain_index;
	uint16_t curr_gain;
	uint8_t curr_gain_index;
	uint16_t resistor_value;
	uint8_t resistor_index;
	ads8681_cfg_t ads8681;
	uint8_t adc_select;
	uint8_t function;
	uint8_t format1;
	uint8_t format2;

}bsp_config_t;

typedef struct bsp_dds
{
	uint8_t divider;
}bsp_dds_t;


struct _bsp
{
	bsp_eeprom_union_t eeprom;
	bsp_trigger_t trigger;
	bsp_calibration_t calibration;
	bsp_security_t security;
	bsp_temperature_t temperature;
	bsp_ip4_lan_t ip4;
	bsp_adc_ads8681_t adc_ads8681[2];
	uint8_t default_cfg;
	uint8_t data_format;
	bsp_measure_t measure;
	bsp_config_t config;
	bsp_result_t result;
	bsp_dds_t dds;
}bsp;

enum trigger_enum
{
	TRG_IMM = 1,
	TRG_EXT = 2,
	TRG_BUS = 3,
	TRG_OUT = 4
};

enum trigger_slope_enum
{
	POS = 1,
	NEG = 2
};

enum format_data_enum
{
	DATA_FORMAT_ASCII = 0,
	DATA_FORMAT_REAL = 1
};

BSP_StatusTypeDef BSP_Init();

#endif /* THIRD_PARTY_BSP_BSP_H_ */
