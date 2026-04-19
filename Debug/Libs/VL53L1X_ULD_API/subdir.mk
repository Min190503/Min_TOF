################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/VL53L1X_ULD_API/VL53L1X_api.c \
../Libs/VL53L1X_ULD_API/VL53L1X_calibration.c 

C_DEPS += \
./Libs/VL53L1X_ULD_API/VL53L1X_api.d \
./Libs/VL53L1X_ULD_API/VL53L1X_calibration.d 

OBJS += \
./Libs/VL53L1X_ULD_API/VL53L1X_api.o \
./Libs/VL53L1X_ULD_API/VL53L1X_calibration.o 


# Each subdirectory must supply rules for building sources it contributes
Libs/VL53L1X_ULD_API/%.o Libs/VL53L1X_ULD_API/%.su Libs/VL53L1X_ULD_API/%.cyclo: ../Libs/VL53L1X_ULD_API/%.c Libs/VL53L1X_ULD_API/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/App" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Libs/VL53L1X_ULD_API" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Libs/MAVLink_V2/common" -I"/home/min/FC_mamab_4_H743_V2/Min_OTF/Sensor/VL53L1X" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-VL53L1X_ULD_API

clean-Libs-2f-VL53L1X_ULD_API:
	-$(RM) ./Libs/VL53L1X_ULD_API/VL53L1X_api.cyclo ./Libs/VL53L1X_ULD_API/VL53L1X_api.d ./Libs/VL53L1X_ULD_API/VL53L1X_api.o ./Libs/VL53L1X_ULD_API/VL53L1X_api.su ./Libs/VL53L1X_ULD_API/VL53L1X_calibration.cyclo ./Libs/VL53L1X_ULD_API/VL53L1X_calibration.d ./Libs/VL53L1X_ULD_API/VL53L1X_calibration.o ./Libs/VL53L1X_ULD_API/VL53L1X_calibration.su

.PHONY: clean-Libs-2f-VL53L1X_ULD_API

