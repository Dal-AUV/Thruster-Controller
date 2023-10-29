################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Interfaces/ros_if.c 

OBJS += \
./Core/Src/Interfaces/ros_if.o 

C_DEPS += \
./Core/Src/Interfaces/ros_if.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Interfaces/%.o Core/Src/Interfaces/%.su Core/Src/Interfaces/%.cyclo: ../Core/Src/Interfaces/%.c Core/Src/Interfaces/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F334x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Interfaces

clean-Core-2f-Src-2f-Interfaces:
	-$(RM) ./Core/Src/Interfaces/ros_if.cyclo ./Core/Src/Interfaces/ros_if.d ./Core/Src/Interfaces/ros_if.o ./Core/Src/Interfaces/ros_if.su

.PHONY: clean-Core-2f-Src-2f-Interfaces

