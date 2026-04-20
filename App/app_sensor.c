#include "app_sensor.h"
#include "vl53l1x_wrapper.h"
#include <string.h>


#define MEDIAN_SIZE	5
#define EMA_ALPHA	0.3f

static TOF_Result_t		tof_raw;
static Altitude_t		altitude;

//Median filter
static uint16_t median_buf[MEDIAN_SIZE];
static uint16_t median_idx = 0;
static uint8_t 	median_filter = 0;

//EMA filter
static float ema_out = 0;
static uint8_t ema_init = 0;

static uint16_t MedianFilter(uint16_t new_val)
{
	median_buf[median_idx] = new_val;
	median_idx = (median_idx + 1) % MEDIAN_SIZE;
	if(median_filter < MEDIAN_SIZE) median_filter++;

	//copy & sort
	uint16_t sorted[MEDIAN_SIZE];
	memcpy(sorted, median_buf, sizeof(sorted));

	for(int i =0; i < median_filter -1; i++)
		for(int j = i + 1; j < median_filter; j++)
			if(sorted[i] > sorted[j]){
				uint16_t tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
	return sorted[median_filter / 2];
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
	median_filter = 0;
	ema_init = 0;
	ema_out = 0;
	memset(median_buf, 0, sizeof(median_buf));
	memset(&altitude, 0, sizeof(altitude));

	return TOF_Init();
}

void App_Sensor_Update(void)
{
	uint8_t ret = TOF_Read(&tof_raw);

	if(ret == 0){
		altitude.raw_mm = tof_raw.distance_mm;
		altitude.is_valid = tof_raw.is_valid;

		if(tof_raw.is_valid){
			//1 Median loai spike
			uint16_t med = MedianFilter(tof_raw.distance_mm);

			//2 EMA - lam muot
			float smooth = EMA_Filter((float)med);

			altitude.altitude_mm = smooth;
			altitude.altitude_m = smooth / 1000.0f;
		}
	}
	//ret == 1 chua co data moi (giu nguyen)
}

Altitude_t* App_Sensor_GetAltitude(void)
{
	return &altitude;
}
