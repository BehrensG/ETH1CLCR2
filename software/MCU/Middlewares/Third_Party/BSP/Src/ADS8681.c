/*
 * ADS8681.c
 *
 *  Created on: Feb 22, 2021
 *      Author: grzegorz
 */

#include "ADS8681.h"
#include "dwt_delay.h"
#include "stm32h7xx_ll_spi.h"
#include <math.h>

double ADS8681_LSB[5] = {0.000375000, 0.000312500, 0.000187500, 0.000156250, 0.000078125};


static BSP_StatusTypeDef ADS8681_SetID(void);
static BSP_StatusTypeDef ADS8681_SetDataOutput(void);
static BSP_StatusTypeDef ADS8681_WriteMSB(uint8_t* cmd, uint8_t* reg, uint8_t* data);
static BSP_StatusTypeDef ADS8681_WriteLSB(uint8_t* cmd, uint8_t* reg, uint8_t* data);
static BSP_StatusTypeDef ADS8681_WriteHWORD(uint8_t* cmd, uint8_t* reg, uint16_t* data);
static BSP_StatusTypeDef ADS8681_ReadLSB(uint8_t* data);
static void ADS8681_ConvertionTime(void);

void ADS8681_CalculateSamplingSetup()
{

	uint32_t samples = 0;
	float delay_tmp = 0;
	int32_t delay = 0;

	samples = (uint32_t)(ADS8681_MAX_SAMPLE_RATE/bsp.config.frequency);

	if(samples > WAV_LEN_MAX)
	{
		samples = WAV_LEN_MAX;
		delay_tmp = ((1/bsp.config.frequency)/samples)*10000000 - ADS8681_MIN_DELAY_x100NS;
		delay = delay_tmp;
		delay = abs(delay);
	}
	else
	{
		delay = 0;

	}

	bsp.config.ads8681.sample_size = samples;
	bsp.config.ads8681.delay = delay;

}

BSP_StatusTypeDef ADS8681_Measurement()
{
	BSP_StatusTypeDef status = 0;
	uint16_t raw_data[2] = {0, 0};
	static double tmp[2][WAV_LEN_MAX];
	uint8_t gain_index = 0;

	ADS8681_CalculateSamplingSetup();

	for(uint16_t x=0; x < bsp.config.ads8681.sample_size; x++)
	{
		ADS8681_RawData(raw_data);
		tmp[0][x] = raw_data[0];
		tmp[1][x] = raw_data[1];
	}

	for(uint16_t x=0; x < bsp.config.ads8681.sample_size; x++)
	{
		tmp[0][x] -= ADS8681_FSR_CENTER;
		tmp[1][x] -= ADS8681_FSR_CENTER;
	}

	for(uint16_t x=0; x < bsp.config.ads8681.sample_size; x++)
	{
		bsp.measure.current.wave[x] = (double)(tmp[0][x]*ADS8681_LSB[bsp.adc_ads8681[0].range]*1.03275776568193267614/bsp.config.volt_gain);
		bsp.measure.voltage.wave[x] = (double)(tmp[1][x]*ADS8681_LSB[bsp.adc_ads8681[1].range]*1.03275776568193267614/bsp.config.curr_gain);
	}

	return BSP_OK;
}

BSP_StatusTypeDef ADS8681_ZeroOffset()
{
	BSP_StatusTypeDef status = BSP_OK;
	uint16_t loop_size = 200;
	float values[2] = {0.0,0.0};
	float tmp[2] = {0.0,0.0};

	HAL_Delay(100);

	status = ADS8681_Measurement(tmp[0],tmp[1]);
	if(BSP_OK != status) return status;

	for (uint16_t x = 0; x < loop_size; x++)
	{
		status = ADS8681_Measurement(tmp[0],tmp[1]);
		if(BSP_OK == status)
		{
			values[0] += tmp[0];
			values[1] += tmp[1];
		}
		else
		{
			break;
		}

	}

	if(BSP_OK == status)
	{
		bsp.adc_ads8681[0].zero_offset = (float)(values[0]/loop_size);
		bsp.adc_ads8681[1].zero_offset = (float)(values[1]/loop_size);

		bsp.adc_ads8681[0].zero_offset *= (float)(-1);
		bsp.adc_ads8681[1].zero_offset *= (float)(-1);
	}

	HAL_Delay(10);

	return status;
}


static BSP_StatusTypeDef BSP_SPI3_Receive(uint32_t* buffer, uint32_t size, uint32_t timeout)
{
	uint32_t tickstart = 0;

    LL_SPI_SetTransferSize(SPI3, size);
    LL_SPI_Enable(SPI3);
    LL_SPI_StartMasterTransfer(SPI3);

    for (uint32_t i = 0; i < size; i++)
    {
        while (LL_SPI_IsActiveFlag_TXP(SPI3) == 0)
       	{
        	if((((HAL_GetTick() - tickstart) >=  timeout) && (timeout != SPI_MAX_DELAY)) || (timeout == 0U))
        	{
        		return BSP_TIMEOUT;
        	}
       	}
        LL_SPI_TransmitData32(SPI3, 0xFFFFFFFF);
    }

    tickstart = HAL_GetTick();

    for (uint32_t i = 0; i < size; i++)
    {
        while (LL_SPI_IsActiveFlag_RXWNE(SPI3) == 0);
        buffer[i] = LL_SPI_ReceiveData32(SPI3);
    }

    while(LL_SPI_IsActiveFlag_EOT(SPI3) == 0)
    {
    	if((((HAL_GetTick() - tickstart) >=  timeout) && (timeout != SPI_MAX_DELAY)) || (timeout == 0U))
    	{
    		return BSP_TIMEOUT;
    	}
   	};

    LL_SPI_ClearFlag_EOT(SPI3);
    LL_SPI_ClearFlag_TXTF(SPI3);
    LL_SPI_SuspendMasterTransfer(SPI3);
    LL_SPI_Disable(SPI3);

    return BSP_OK;
}

static BSP_StatusTypeDef BSP_SPI3_Transmit(uint32_t* buffer, uint32_t size, uint32_t timeout)
{
	uint32_t rx_buffer[2];
	uint32_t tickstart = 0;

	LL_SPI_SetTransferSize(SPI3, size);
    LL_SPI_Enable(SPI3);
    LL_SPI_StartMasterTransfer(SPI3);

    for (uint32_t i = 0; i < size; i++)
    {
        while (LL_SPI_IsActiveFlag_TXP(SPI3) == 0);
        LL_SPI_TransmitData32(SPI3, buffer[i]);
    }

    tickstart = HAL_GetTick();

    for (uint32_t i = 0; i < size; i++)
    {
        while (LL_SPI_IsActiveFlag_RXWNE(SPI3) == 0)
        {
        	if((((HAL_GetTick() - tickstart) >=  timeout) && (timeout != SPI_MAX_DELAY)) || (timeout == 0U))
        	{
        		return BSP_TIMEOUT;
        	}
        }

        rx_buffer[i] = LL_SPI_ReceiveData32(SPI3);
    }

    while (LL_SPI_IsActiveFlag_EOT(SPI3) == 0)
    {
    	if((((HAL_GetTick() - tickstart) >=  timeout) && (timeout != SPI_MAX_DELAY)) || (timeout == 0U))
    	{
    		return BSP_TIMEOUT;
    	}
    }

    LL_SPI_ClearFlag_EOT(SPI3);
    LL_SPI_ClearFlag_TXTF(SPI3);
    LL_SPI_SuspendMasterTransfer(SPI3);
    LL_SPI_Disable(SPI3);

    return BSP_OK;
}

BSP_StatusTypeDef ADS8681_RawData(uint16_t* raw_data)
{
	BSP_StatusTypeDef status = BSP_OK;

	uint32_t rx_data[2];

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	//ADS8681_ConvertionTime();
	if(bsp.config.ads8681.delay)
	{
		delay100NS_ASM(bsp.config.ads8681.delay);
	}
	LL_GPIO_SetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	status = BSP_SPI3_Receive(rx_data, 2, 10000);
	LL_GPIO_SetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);

	if(BSP_OK != status)
	{
		return status;
	}
	else
	{
		raw_data[0] = (uint16_t)(rx_data[1] >> 16);
		raw_data[1] = (uint16_t)(rx_data[0] >> 16);

		return BSP_OK;
	}

}


BSP_StatusTypeDef ADS8681_Init(void)
{
	BSP_StatusTypeDef status = BSP_OK;
	uint8_t range[2] = {0,0};

	status = ADS8681_SetID();
	if(BSP_OK != status) return status;

	range[0] = bsp.adc_ads8681[0].range;
	range[1] = bsp.adc_ads8681[1].range;

	status = ADS8681_SetDataOutput();
	if(BSP_OK != status) return status;

	status = ADS8681_SetRange(range);

	return status;
}

static BSP_StatusTypeDef ADS8681_SetDataOutput(void)
{

	uint8_t cmd[2];
	uint8_t reg[2];
	uint16_t tx_hword[2];

	cmd[0] = WRITE_HWORD;
	cmd[1] = WRITE_HWORD;

	reg[0] = DATAOUT_CTL_REG;
	reg[1] = DATAOUT_CTL_REG;

	tx_hword[0] = 0x7D08;
	tx_hword[1] = 0x7D08;

	return ADS8681_WriteHWORD(cmd, reg, tx_hword);

}


BSP_StatusTypeDef ADS8681_SetRange(uint8_t range[])
{
	BSP_StatusTypeDef status = BSP_OK;
	uint8_t cmd[2]={0,0};
	uint8_t reg[2]={0,0};
	uint8_t tx_data[2]={0,0};
	uint8_t rx_data[2]={0,0};


	cmd[0] = WRITE_LSB;
	cmd[1] = WRITE_LSB;

	reg[0] = RANGE_SEL_REG;
	reg[1] = RANGE_SEL_REG;

	tx_data[1] = range[1];
	tx_data[0] = range[0];

	status = ADS8681_WriteLSB(cmd, reg, tx_data);
	if(BSP_OK != status){return status;}

	DWT_Delay_us(10);

	return status;
}

static BSP_StatusTypeDef ADS8681_SetID(void)
{
	uint8_t cmd[2]={0,0};
	uint8_t reg[2]={0,0};
	uint8_t tx_data[2]={0,0};
	uint8_t rx_data[2]={0,0};

	BSP_StatusTypeDef status = BSP_OK;

	cmd[0] = WRITE_LSB;
	cmd[1] = WRITE_LSB;

	reg[0] = DEVICE_ID_REG + 0x02;
	reg[1] = DEVICE_ID_REG + 0x02;

	tx_data[1] = ADS8681_ID1;
	tx_data[0] = ADS8681_ID2;

	status = ADS8681_WriteLSB(cmd, reg, tx_data);
	if(BSP_OK != status) return status;

	HAL_Delay(1);

	cmd[0] = READ_BYTE;
	cmd[1] = READ_BYTE;

	reg[0] = DEVICE_ID_REG + 0x02;
	reg[1] = DEVICE_ID_REG + 0x02;

	tx_data[0] = 0x00;
	tx_data[1] = 0x00;

	status = ADS8681_WriteLSB(cmd, reg, tx_data);
	if(BSP_OK != status) return status;

	HAL_Delay(1);

	status = ADS8681_ReadLSB(rx_data);
	if(BSP_OK != status) return status;

	tx_data[1] = ADS8681_ID1;
	tx_data[0] = ADS8681_ID2;

	for (uint8_t x = 0; x < 2; x++)
	{
		if(rx_data[x] != tx_data[x])
		{
			return BSP_ADC_CONFIG_ERROR;
		}
	}

	return BSP_OK;
}


static BSP_StatusTypeDef ADS8681_ReadLSB(uint8_t* data)
{

	BSP_StatusTypeDef status = BSP_OK;
	uint32_t rx_data[2] = {0x00000000,0x00000000};

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	//status = HAL_SPI_Receive(&hspi3, (uint8_t*)rx_data, 2, 1000);
	status = BSP_SPI3_Receive(rx_data, 2,10000);
	LL_GPIO_SetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);


	data[0] = rx_data[0] >> 24;
	data[1] = rx_data[1] >> 24;

	return status;

}

static BSP_StatusTypeDef ADS8681_WriteHWORD(uint8_t* cmd, uint8_t* reg, uint16_t* data)
{

	BSP_StatusTypeDef status = BSP_OK;
	uint32_t tx_data[2] = {0x00000000,0x00000000};

	tx_data[0] = cmd[0] << 24 | reg[0] << 16 | (data[0] & 0x0000FFFF);
	tx_data[1] = cmd[1] << 24 | reg[1] << 16 | (data[1] & 0x0000FFFF);

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	//status = HAL_SPI_Transmit(&hspi3, (uint8_t*)tx_data, 2, 1000);
	status = BSP_SPI3_Transmit(tx_data, 2, 10000);
	LL_GPIO_SetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);

	return status;
}

static BSP_StatusTypeDef ADS8681_WriteMSB(uint8_t* cmd, uint8_t* reg, uint8_t* data)
{
	BSP_StatusTypeDef status = BSP_OK;
	uint32_t tx_data[2] = {0x00000000,0x00000000};


	tx_data[0] = cmd[0] << 24 | reg[0] << 16 | (data[0] & 0x000000FF);
	tx_data[1] = cmd[1] << 24 | reg[1] << 16 | (data[1] & 0x000000FF);


	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	//status = HAL_SPI_Transmit(&hspi3, (uint8_t*)tx_data, 2, 1000);
	status = BSP_SPI3_Transmit(tx_data, 2,10000);
	LL_GPIO_SetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);

	return status;
}

static BSP_StatusTypeDef ADS8681_WriteLSB(uint8_t* cmd, uint8_t* reg, uint8_t* data)
{

	BSP_StatusTypeDef status = BSP_OK;
	uint32_t tx_data[2] = {0x00000000,0x00000000};

	tx_data[0] = cmd[0] << 24 | reg[0] << 16 | (data[0] & 0x000000FF);
	tx_data[1] = cmd[1] << 24 | reg[1] << 16 | (data[1] & 0x000000FF);

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	//status = HAL_SPI_Transmit(&hspi3, (uint8_t*)tx_data, 2, 1000);
	status = BSP_SPI3_Transmit(tx_data, 2, 10000);
	LL_GPIO_SetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);

	return status;
}


static void ADS8681_ConvertionTime(void)
{
    uint32_t startTick = DWT->CYCCNT,
             delayTicks = 1 * (SystemCoreClock/15000000);

    while (DWT->CYCCNT - startTick < delayTicks);
}
