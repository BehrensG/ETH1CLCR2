################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/BSP/Src/ADS8681.c \
../Middlewares/Third_Party/BSP/Src/HDC1080.c \
../Middlewares/Third_Party/BSP/Src/bsp.c \
../Middlewares/Third_Party/BSP/Src/dwt_delay.c \
../Middlewares/Third_Party/BSP/Src/ee24.c \
../Middlewares/Third_Party/BSP/Src/eeprom.c \
../Middlewares/Third_Party/BSP/Src/heap_useNewlib.c \
../Middlewares/Third_Party/BSP/Src/relays.c \
../Middlewares/Third_Party/BSP/Src/scpi_def.c \
../Middlewares/Third_Party/BSP/Src/scpi_server.c \
../Middlewares/Third_Party/BSP/Src/scpi_system.c 

OBJS += \
./Middlewares/Third_Party/BSP/Src/ADS8681.o \
./Middlewares/Third_Party/BSP/Src/HDC1080.o \
./Middlewares/Third_Party/BSP/Src/bsp.o \
./Middlewares/Third_Party/BSP/Src/dwt_delay.o \
./Middlewares/Third_Party/BSP/Src/ee24.o \
./Middlewares/Third_Party/BSP/Src/eeprom.o \
./Middlewares/Third_Party/BSP/Src/heap_useNewlib.o \
./Middlewares/Third_Party/BSP/Src/relays.o \
./Middlewares/Third_Party/BSP/Src/scpi_def.o \
./Middlewares/Third_Party/BSP/Src/scpi_server.o \
./Middlewares/Third_Party/BSP/Src/scpi_system.o 

C_DEPS += \
./Middlewares/Third_Party/BSP/Src/ADS8681.d \
./Middlewares/Third_Party/BSP/Src/HDC1080.d \
./Middlewares/Third_Party/BSP/Src/bsp.d \
./Middlewares/Third_Party/BSP/Src/dwt_delay.d \
./Middlewares/Third_Party/BSP/Src/ee24.d \
./Middlewares/Third_Party/BSP/Src/eeprom.d \
./Middlewares/Third_Party/BSP/Src/heap_useNewlib.d \
./Middlewares/Third_Party/BSP/Src/relays.d \
./Middlewares/Third_Party/BSP/Src/scpi_def.d \
./Middlewares/Third_Party/BSP/Src/scpi_server.d \
./Middlewares/Third_Party/BSP/Src/scpi_system.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/BSP/Src/%.o: ../Middlewares/Third_Party/BSP/Src/%.c Middlewares/Third_Party/BSP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DDATA_IN_D2_SRAM -DUSE_HAL_DRIVER -DSTM32H743xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Middlewares/Third_Party/BSP/Inc -I../Middlewares/Third_Party/BSP/Src -I"/home/grzegorz/git/ETH1CLCR2/software/MCU/Middlewares/Third_Party/scpi-2.1/libscpi/inc/scpi" -I"/home/grzegorz/git/ETH1CLCR2/software/MCU/Middlewares/Third_Party/scpi-2.1/libscpi/inc" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

