################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sensor/VL53L1X/vl53l1x_wrapper.c 

C_DEPS += \
./Sensor/VL53L1X/vl53l1x_wrapper.d 

OBJS += \
./Sensor/VL53L1X/vl53l1x_wrapper.o 


# Each subdirectory must supply rules for building sources it contributes
Sensor/VL53L1X/%.o Sensor/VL53L1X/%.su Sensor/VL53L1X/%.cyclo: ../Sensor/VL53L1X/%.c Sensor/VL53L1X/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/App" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Libs/VL53L1X_ULD_API" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Libs/MAVLink_V2/common" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor/VL53L1X" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor/PMW3901" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Sensor-2f-VL53L1X

clean-Sensor-2f-VL53L1X:
	-$(RM) ./Sensor/VL53L1X/vl53l1x_wrapper.cyclo ./Sensor/VL53L1X/vl53l1x_wrapper.d ./Sensor/VL53L1X/vl53l1x_wrapper.o ./Sensor/VL53L1X/vl53l1x_wrapper.su

.PHONY: clean-Sensor-2f-VL53L1X

