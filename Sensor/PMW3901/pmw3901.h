#ifndef PMW3901_H
#define PMW3901_H

#include <stdint.h>

typedef struct {
	int16_t deltaX;		//Pixel shift theo truc X
	int16_t deltaY;		//Pixel shift theo truc Y
	uint8_t squal;		//Surface Quality
	uint8_t is_valid;	// 1: Valid Data
} PMW3901_Result_t;

uint8_t PMW3901_Init(void);
void PMW3901_Read(PMW3901_Result_t *result);

#endif
