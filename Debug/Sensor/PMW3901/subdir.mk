################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sensor/PMW3901/pwm3901.c 

C_DEPS += \
./Sensor/PMW3901/pwm3901.d 

OBJS += \
./Sensor/PMW3901/pwm3901.o 


# Each subdirectory must supply rules for building sources it contributes
Sensor/PMW3901/%.o Sensor/PMW3901/%.su Sensor/PMW3901/%.cyclo: ../Sensor/PMW3901/%.c Sensor/PMW3901/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/App" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Libs/VL53L1X_ULD_API" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Libs/MAVLink_V2/common" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor/VL53L1X" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor/PMW3901" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Sensor-2f-PMW3901

clean-Sensor-2f-PMW3901:
	-$(RM) ./Sensor/PMW3901/pwm3901.cyclo ./Sensor/PMW3901/pwm3901.d ./Sensor/PMW3901/pwm3901.o ./Sensor/PMW3901/pwm3901.su

.PHONY: clean-Sensor-2f-PMW3901

