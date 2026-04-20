################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/app_sensor.c 

C_DEPS += \
./App/app_sensor.d 

OBJS += \
./App/app_sensor.o 


# Each subdirectory must supply rules for building sources it contributes
App/%.o App/%.su App/%.cyclo: ../App/%.c App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/App" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Libs/VL53L1X_ULD_API" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Libs/MAVLink_V2/common" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor/VL53L1X" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App

clean-App:
	-$(RM) ./App/app_sensor.cyclo ./App/app_sensor.d ./App/app_sensor.o ./App/app_sensor.su

.PHONY: clean-App

