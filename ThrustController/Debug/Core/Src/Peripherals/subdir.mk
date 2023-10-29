################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Peripherals/dma.c \
../Core/Src/Peripherals/usart.c 

OBJS += \
./Core/Src/Peripherals/dma.o \
./Core/Src/Peripherals/usart.o 

C_DEPS += \
./Core/Src/Peripherals/dma.d \
./Core/Src/Peripherals/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Peripherals/%.o Core/Src/Peripherals/%.su Core/Src/Peripherals/%.cyclo: ../Core/Src/Peripherals/%.c Core/Src/Peripherals/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F334x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Peripherals

clean-Core-2f-Src-2f-Peripherals:
	-$(RM) ./Core/Src/Peripherals/dma.cyclo ./Core/Src/Peripherals/dma.d ./Core/Src/Peripherals/dma.o ./Core/Src/Peripherals/dma.su ./Core/Src/Peripherals/usart.cyclo ./Core/Src/Peripherals/usart.d ./Core/Src/Peripherals/usart.o ./Core/Src/Peripherals/usart.su

.PHONY: clean-Core-2f-Src-2f-Peripherals

