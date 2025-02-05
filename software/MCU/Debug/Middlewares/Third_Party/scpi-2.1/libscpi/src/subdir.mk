################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/scpi-2.1/libscpi/src/error.c \
../Middlewares/Third_Party/scpi-2.1/libscpi/src/expression.c \
../Middlewares/Third_Party/scpi-2.1/libscpi/src/fifo.c \
../Middlewares/Third_Party/scpi-2.1/libscpi/src/ieee488.c \
../Middlewares/Third_Party/scpi-2.1/libscpi/src/lexer.c \
../Middlewares/Third_Party/scpi-2.1/libscpi/src/minimal.c \
../Middlewares/Third_Party/scpi-2.1/libscpi/src/parser.c \
../Middlewares/Third_Party/scpi-2.1/libscpi/src/units.c \
../Middlewares/Third_Party/scpi-2.1/libscpi/src/utils.c 

OBJS += \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/error.o \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/expression.o \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/fifo.o \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/ieee488.o \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/lexer.o \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/minimal.o \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/parser.o \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/units.o \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/utils.o 

C_DEPS += \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/error.d \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/expression.d \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/fifo.d \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/ieee488.d \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/lexer.d \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/minimal.d \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/parser.d \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/units.d \
./Middlewares/Third_Party/scpi-2.1/libscpi/src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/scpi-2.1/libscpi/src/%.o Middlewares/Third_Party/scpi-2.1/libscpi/src/%.su Middlewares/Third_Party/scpi-2.1/libscpi/src/%.cyclo: ../Middlewares/Third_Party/scpi-2.1/libscpi/src/%.c Middlewares/Third_Party/scpi-2.1/libscpi/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DDATA_IN_D2_SRAM -DUSE_HAL_DRIVER -DSTM32H743xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Middlewares/Third_Party/BSP/Inc -I../Middlewares/Third_Party/BSP/Src -I"/home/grzegorz/git/ETH1CLCR2/software/MCU/Middlewares/Third_Party/scpi-2.1/libscpi/inc/scpi" -I"/home/grzegorz/git/ETH1CLCR2/software/MCU/Middlewares/Third_Party/scpi-2.1/libscpi/inc" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=softfp -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-scpi-2d-2-2e-1-2f-libscpi-2f-src

clean-Middlewares-2f-Third_Party-2f-scpi-2d-2-2e-1-2f-libscpi-2f-src:
	-$(RM) ./Middlewares/Third_Party/scpi-2.1/libscpi/src/error.cyclo ./Middlewares/Third_Party/scpi-2.1/libscpi/src/error.d ./Middlewares/Third_Party/scpi-2.1/libscpi/src/error.o ./Middlewares/Third_Party/scpi-2.1/libscpi/src/error.su ./Middlewares/Third_Party/scpi-2.1/libscpi/src/expression.cyclo ./Middlewares/Third_Party/scpi-2.1/libscpi/src/expression.d ./Middlewares/Third_Party/scpi-2.1/libscpi/src/expression.o ./Middlewares/Third_Party/scpi-2.1/libscpi/src/expression.su ./Middlewares/Third_Party/scpi-2.1/libscpi/src/fifo.cyclo ./Middlewares/Third_Party/scpi-2.1/libscpi/src/fifo.d ./Middlewares/Third_Party/scpi-2.1/libscpi/src/fifo.o ./Middlewares/Third_Party/scpi-2.1/libscpi/src/fifo.su ./Middlewares/Third_Party/scpi-2.1/libscpi/src/ieee488.cyclo ./Middlewares/Third_Party/scpi-2.1/libscpi/src/ieee488.d ./Middlewares/Third_Party/scpi-2.1/libscpi/src/ieee488.o ./Middlewares/Third_Party/scpi-2.1/libscpi/src/ieee488.su ./Middlewares/Third_Party/scpi-2.1/libscpi/src/lexer.cyclo ./Middlewares/Third_Party/scpi-2.1/libscpi/src/lexer.d ./Middlewares/Third_Party/scpi-2.1/libscpi/src/lexer.o ./Middlewares/Third_Party/scpi-2.1/libscpi/src/lexer.su ./Middlewares/Third_Party/scpi-2.1/libscpi/src/minimal.cyclo ./Middlewares/Third_Party/scpi-2.1/libscpi/src/minimal.d ./Middlewares/Third_Party/scpi-2.1/libscpi/src/minimal.o ./Middlewares/Third_Party/scpi-2.1/libscpi/src/minimal.su ./Middlewares/Third_Party/scpi-2.1/libscpi/src/parser.cyclo ./Middlewares/Third_Party/scpi-2.1/libscpi/src/parser.d ./Middlewares/Third_Party/scpi-2.1/libscpi/src/parser.o ./Middlewares/Third_Party/scpi-2.1/libscpi/src/parser.su ./Middlewares/Third_Party/scpi-2.1/libscpi/src/units.cyclo ./Middlewares/Third_Party/scpi-2.1/libscpi/src/units.d ./Middlewares/Third_Party/scpi-2.1/libscpi/src/units.o ./Middlewares/Third_Party/scpi-2.1/libscpi/src/units.su ./Middlewares/Third_Party/scpi-2.1/libscpi/src/utils.cyclo ./Middlewares/Third_Party/scpi-2.1/libscpi/src/utils.d ./Middlewares/Third_Party/scpi-2.1/libscpi/src/utils.o ./Middlewares/Third_Party/scpi-2.1/libscpi/src/utils.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-scpi-2d-2-2e-1-2f-libscpi-2f-src

