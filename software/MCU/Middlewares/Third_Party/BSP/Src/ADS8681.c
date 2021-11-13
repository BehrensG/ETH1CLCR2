/*
 * ADS8681.c
 *
 *  Created on: Feb 22, 2021
 *      Author: grzegorz
 */

#include "ADS8681.h"
#include "dwt_delay.h"

double ADS8681_LSB[5] = {0.000375000, 0.000312500, 0.000187500, 0.000156250, 0.000078125};


static void ADS8681_Set_ID(void);
static void ADS8681_Set_Data_Output(void);
static void ADS8681_Write_MSB(uint8_t* cmd, uint8_t* reg, uint8_t* data);
static void ADS8681_Write_LSB(uint8_t* cmd, uint8_t* reg, uint8_t* data);
static void ADS8681_Write_HWORD(uint8_t* cmd, uint8_t* reg, uint16_t* data);
static void ADS8681_Read_LSB(uint8_t* data);
static void ADS8681_Convertion_Time(void);



static inline BSP_SPI_Receive(uint32_t* buffer, uint32_t size)
{
    LL_SPI_SetTransferSize(SPI3, size);
    LL_SPI_Enable(SPI3);
    LL_SPI_StartMasterTransfer(SPI3);

    for (uint32_t i = 0; i < size; i++)
    {
        while (LL_SPI_IsActiveFlag_TXP(SPI3) == 0);
        LL_SPI_TransmitData32(SPI3, 0xFFFFFFFF);
    }


    for (uint32_t i = 0; i < size; i++)
    {
        while (LL_SPI_IsActiveFlag_RXWNE(SPI3) == 0);
        buffer[i] = LL_SPI_ReceiveData32(SPI3);
    }

    while (LL_SPI_IsActiveFlag_EOT(SPI3) == 0);
    LL_SPI_ClearFlag_EOT(SPI3);
    LL_SPI_ClearFlag_TXTF(SPI3);
    LL_SPI_SuspendMasterTransfer(SPI3);
    LL_SPI_Disable(SPI3);
}

static inline BSP_SPI_Transmit(uint32_t* buffer, uint32_t size)
{
	uint32_t rx_buffer[2];

    LL_SPI_SetTransferSize(SPI3, size);
    LL_SPI_Enable(SPI3);
    LL_SPI_StartMasterTransfer(SPI3);

    for (uint32_t i = 0; i < size; i++)
    {
        while (LL_SPI_IsActiveFlag_TXP(SPI3) == 0);
        LL_SPI_TransmitData32(SPI3, buffer[i]);
    }

    for (uint32_t i = 0; i < size; i++)
    {
        while (LL_SPI_IsActiveFlag_RXWNE(SPI3) == 0);
        rx_buffer[i] = LL_SPI_ReceiveData32(SPI3);
    }

    while (LL_SPI_IsActiveFlag_EOT(SPI3) == 0);
    LL_SPI_ClearFlag_EOT(SPI3);
    LL_SPI_ClearFlag_TXTF(SPI3);
    LL_SPI_SuspendMasterTransfer(SPI3);
    LL_SPI_Disable(SPI3);
}

void ADS8681_Raw_Data(uint16_t* raw_data)
{

	uint32_t rx_data[2];

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	ADS8681_Convertion_Time();
	LL_GPIO_WriteOutputPort(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	BSP_SPI_Receive(rx_data, 2);
	LL_GPIO_WriteOutputPort(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);

	raw_data[0] = (uint16_t)(rx_data[2] >> 16);
	raw_data[1] = (uint16_t)(rx_data[1] >> 16);

}


void ADS8681_Init(void)
{

	ADS8681_Set_ID();

	//bsp.adc[0].range = ADS8681_RANGE_3VREF;
	//bsp.adc[1].range = ADS8681_RANGE_3VREF;

	ADS8681_Set_Data_Output();

}

static void ADS8681_Set_Data_Output(void)
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

	ADS8681_Write_HWORD(cmd, reg, tx_hword);

}


void ADS8681_Set_Range(uint8_t range[])
{
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

	ADS8681_Write_LSB(cmd, reg, tx_data);

	DWT_Delay_us(10);

}

static void ADS8681_Set_ID(void)
{
	uint8_t cmd[2]={0,0};
	uint8_t reg[2]={0,0};
	uint8_t tx_data[2]={0,0};
	uint8_t rx_data[2]={0,0};

	cmd[0] = WRITE_LSB;
	cmd[1] = WRITE_LSB;

	reg[0] = DEVICE_ID_REG + 0x02;
	reg[1] = DEVICE_ID_REG + 0x02;

	tx_data[1] = ADS8681_ID1;
	tx_data[0] = ADS8681_ID2;

	ADS8681_Write_LSB(cmd, reg, tx_data);

	DWT_Delay_us(1);

	cmd[0] = READ_BYTE;
	cmd[1] = READ_BYTE;
	cmd[2] = READ_BYTE;

	reg[0] = DEVICE_ID_REG + 0x02;
	reg[1] = DEVICE_ID_REG + 0x02;

	tx_data[0] = 0x00;
	tx_data[1] = 0x00;

	ADS8681_Write_LSB(cmd, reg, tx_data);

	DWT_Delay_us(1);

	ADS8681_Read_LSB(rx_data);

	tx_data[1] = ADS8681_ID1;
	tx_data[0] = ADS8681_ID2;

}


static void ADS8681_Read_LSB(uint8_t* data)
{

	uint32_t rx_data[2] = {0x00000000,0x00000000};

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	BSP_SPI_Receive(rx_data, 2);
	LL_GPIO_WriteOutputPort(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);


	data[0] = rx_data[0] >> 24;
	data[1] = rx_data[1] >> 24;

}

static void ADS8681_Write_HWORD(uint8_t* cmd, uint8_t* reg, uint16_t* data)
{

	uint32_t tx_data[2] = {0x00000000,0x00000000};

	tx_data[0] = cmd[0] << 24 | reg[0] << 16 | (data[0] & 0x0000FFFF);
	tx_data[1] = cmd[1] << 24 | reg[1] << 16 | (data[1] & 0x0000FFFF);

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	//status = HAL_SPI_Transmit(&hspi3, (uint8_t*)tx_data, 3, 1000);
	BSP_SPI_Transmit(tx_data, 2);
	LL_GPIO_WriteOutputPort(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);


}

static void ADS8681_Write_MSB(uint8_t* cmd, uint8_t* reg, uint8_t* data)
{
	uint32_t tx_data[2] = {0x00000000,0x00000000};


	tx_data[0] = cmd[0] << 24 | reg[0] << 16 | (data[0] & 0x000000FF);
	tx_data[1] = cmd[1] << 24 | reg[1] << 16 | (data[1] & 0x000000FF);


	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	//status = HAL_SPI_Transmit(&hspi3, (uint8_t*)tx_data, 3, 1000);
	BSP_SPI_Transmit(tx_data, 2);
	LL_GPIO_WriteOutputPort(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);

}

static void ADS8681_Write_LSB(uint8_t* cmd, uint8_t* reg, uint8_t* data)
{

	uint32_t tx_data[2] = {0x00000000,0x00000000};

	tx_data[0] = cmd[0] << 24 | reg[0] << 16 | (data[0] & 0x000000FF);
	tx_data[1] = cmd[1] << 24 | reg[1] << 16 | (data[1] & 0x000000FF);

	LL_GPIO_ResetOutputPin(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);
	//status = HAL_SPI_Transmit(&hspi3, (uint8_t*)tx_data, 3, 1000);
	BSP_SPI_Transmit(tx_data, 2);
	LL_GPIO_WriteOutputPort(SPI3_NSS_GPIO_Port, SPI3_NSS_Pin);

}

static void ADS8681_Convertion_Time(void)
{
    uint32_t startTick = DWT->CYCCNT,
             delayTicks = 1 * (SystemCoreClock/15000000);

    while (DWT->CYCCNT - startTick < delayTicks);
}
