################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LWIP/Target/ethernetif_fix.c 

OBJS += \
./LWIP/Target/ethernetif_fix.o 

C_DEPS += \
./LWIP/Target/ethernetif_fix.d 


# Each subdirectory must supply rules for building sources it contributes
LWIP/Target/%.o LWIP/Target/%.su: ../LWIP/Target/%.c LWIP/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DDATA_IN_D2_SRAM -DUSE_HAL_DRIVER -DSTM32H743xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Middlewares/Third_Party/BSP/Inc -I../Middlewares/Third_Party/BSP/Src -I"/home/grzegorz/git/ETH1CLCR2/software/MCU/Middlewares/Third_Party/scpi-2.1/libscpi/inc/scpi" -I"/home/grzegorz/git/ETH1CLCR2/software/MCU/Middlewares/Third_Party/scpi-2.1/libscpi/inc" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=softfp -mthumb -o "$@"

clean: clean-LWIP-2f-Target

clean-LWIP-2f-Target:
	-$(RM) ./LWIP/Target/ethernetif_fix.d ./LWIP/Target/ethernetif_fix.o ./LWIP/Target/ethernetif_fix.su

.PHONY: clean-LWIP-2f-Target

