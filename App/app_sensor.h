#ifndef APP_SENSOR_H
#define APP_SENSOR_H

#include <stdint.h>
#include "pmw3901.h"

typedef struct {
	float altitude_mm;		//do cao da loc(mm)
	float altitude_m;		//do cao da loc(m)
	uint16_t raw_mm;		// data tho(mm)
	uint16_t is_valid;		// 1=OK, 0 = ERROR
} Altitude_t;

typedef struct {
	Altitude_t alt;
	PMW3901_Result_t flow;
} App_SensorData_t;

uint8_t App_Sensor_Init(void);

void App_Sensor_Update(void);

Altitude_t* App_Sensor_GetAltitude(void);

App_SensorData_t* App_Sensor_GetData(void);

#endif
