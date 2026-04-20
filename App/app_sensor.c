#include "app_sensor.h"
#include "vl53l1x_wrapper.h"
#include <string.h>
#include "pmw3901.h"

#define MEDIAN_SIZE	5
#define EMA_ALPHA	0.3f

static TOF_Result_t		tof_raw;
static App_SensorData_t sensor_data;

//Median filter
static uint16_t median_buf[MEDIAN_SIZE];
static uint16_t median_idx = 0;
static uint8_t 	median_filter_count = 0;

//EMA filter
static float ema_out = 0;
static uint8_t ema_init = 0;

static uint16_t MedianFilter(uint16_t new_val)
{
	median_buf[median_idx] = new_val;
	median_idx = (median_idx + 1) % MEDIAN_SIZE;
	if(median_filter_count < MEDIAN_SIZE) median_filter_count++;

	//copy & sort
	uint16_t sorted[MEDIAN_SIZE];
	memcpy(sorted, median_buf, sizeof(sorted));

	for(int i =0; i < median_filter_count -1; i++)
		for(int j = i + 1; j < median_filter_count; j++)
			if(sorted[i] > sorted[j]){
				uint16_t tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
	//Gia tri nam chinh giua mang
	return sorted[median_filter_count / 2];
}


//EMA LOW_PASS
static float EMA_Filter(float new_val)
{
	if(!ema_init){
		ema_out = new_val;
		ema_init = 1;
		return ema_out;
	}
	ema_out = EMA_ALPHA * new_val + (1.0f - EMA_ALPHA) * ema_out;
	return ema_out;
}



uint8_t App_Sensor_Init(void)
{
	//Reset filter state
	median_idx = 0;
	median_filter_count = 0;
	ema_init = 0;
	ema_out = 0;
	memset(median_buf, 0, sizeof(median_buf));
	memset(&sensor_data, 0, sizeof(sensor_data));

	uint8_t tof_err = TOF_Init();
	if(tof_err != 0){
		return tof_err;   //TOF Error
	}

	uint8_t pmw_err = PMW3901_Init();
	if(pmw_err != 0){
		return (100 + pmw_err); // >100 de phan biet la loi cua pmw
	}

	//TOF & PMW = OK
	return 0;
}

void App_Sensor_Update(void)
{
	uint8_t ret = TOF_Read(&tof_raw);

	if(ret == 0){
		sensor_data.alt.raw_mm = tof_raw.distance_mm;
		sensor_data.alt.is_valid = tof_raw.is_valid;

		if(tof_raw.is_valid){
			//Loc Median loai bo nhieu
			uint16_t med = MedianFilter(tof_raw.distance_mm);

			//cho qua EMA lam muot
			float smooth = EMA_Filter((float)med);

			//Luu vao struct
			sensor_data.alt.altitude_mm = smooth;
			sensor_data.alt.altitude_m = smooth / 1000.0f;
		}
	}
	//ret == 1 I2c chua co data moi, giu nguyen do cao

	//Quet data di chuyen ngang
	PMW3901_Read(&sensor_data.flow);
}

App_SensorData_t* App_Sensor_GetData(void)
{
	return &sensor_data;
}
