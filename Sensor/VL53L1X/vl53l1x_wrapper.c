#include "vl53l1x_wrapper.h"
#include "VL53L1X_api.h"
#include "main.h"

uint8_t TOF_Init(void){
	uint8_t boot = 0;
	uint8_t status;
	uint16_t sensor_id;


	//cho sensor boot
	while(boot == 0){
		status = VL53L1X_BootState(TOF_I2C_ADDR, &boot);
		if(status) return status;
		HAL_Delay(2);
	}

	//ktra sensor ID (0xEACC)
	status = VL53L1X_GetSensorId(TOF_I2C_ADDR, &sensor_id);
	if(status) return status;
	if(sensor_id != 0xEACC) return 99; //sai sensor

	//Init
	status = VL53L1X_SensorInit(TOF_I2C_ADDR);
	if(status) return status;

	//cau hinh
	VL53L1X_SetDistanceMode(TOF_I2C_ADDR, TOF_MODE_SHORT);     // 1.3m, tốt cho drone bay thấp
	VL53L1X_SetTimingBudgetInMs(TOF_I2C_ADDR, 33);             // 33ms → ~30Hz
	VL53L1X_SetInterMeasurementInMs(TOF_I2C_ADDR, 35);         // ≥ timing budget

	//do lien tuc
	status = VL53L1X_StartRanging(TOF_I2C_ADDR);
	return status;
}


uint8_t TOF_Read(TOF_Result_t *result)
{
    uint8_t ready = 0;
    uint8_t status;
    /* Check xem có data mới chưa */
    status = VL53L1X_CheckForDataReady(TOF_I2C_ADDR, &ready);
    if (status) return 2;
    if (!ready) return 1;  // chưa có data mới
    /* Đọc kết quả */
    VL53L1X_GetDistance(TOF_I2C_ADDR, &result->distance_mm);
    VL53L1X_GetSignalRate(TOF_I2C_ADDR, &result->signal_rate);
    VL53L1X_GetAmbientRate(TOF_I2C_ADDR, &result->ambient_rate);
    VL53L1X_GetRangeStatus(TOF_I2C_ADDR, &result->range_status);
    /* Clear interrupt cho lần đo tiếp */
    VL53L1X_ClearInterrupt(TOF_I2C_ADDR);
    /* Đánh giá data có hợp lệ không */
    result->is_valid = (result->range_status == 0) ? 1 : 0;
    return 0;
}
uint8_t TOF_ReadBlocking(TOF_Result_t *result)
{
    uint8_t ret;
    /* Chờ đến khi có data */
    do {
        ret = TOF_Read(result);
    } while (ret == 1);
    return ret;
}
