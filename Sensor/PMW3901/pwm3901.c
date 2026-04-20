#include "pmw3901.h"
#include "spi.h"
#include "gpio.h"
#include "main.h"


#define CS_LOW()		HAL_GPIO_WritePin(GPIOA, SPI_CS_Pin, GPIO_PIN_RESET)
#define CS_HIGH()		HAL_GPIO_WritePin(GPIOA, SPI_CS_Pin, GPIO_PIN_SET)

static void pmw3901_write_reg(uint8_t reg, uint8_t value){
	uint8_t tx_buf[2] = {reg | 0x80, value};
	CS_LOW();
	HAL_SPI_Transmit(&hspi1, tx_buf, 2, 100);
	CS_HIGH();
	for(volatile int i=0; i<100; i++);
}

static uint8_t pmw3901_read_reg(uint8_t reg){
	uint8_t tx_buf[2] = {reg & 0x7F, 0x00};
	uint8_t rx_buf[2];
	CS_LOW();
	HAL_SPI_TransmitReceive(&hspi1, tx_buf, rx_buf, 2, 100);
	CS_HIGH();
	for(volatile int i=0; i<100; i++);
	return rx_buf[1];
}

static void pmw3901_secret_init(void){
	pmw3901_write_reg(0x7F, 0x00); pmw3901_write_reg(0x61, 0xAD); pmw3901_write_reg(0x7F, 0x03);
	pmw3901_write_reg(0x40, 0x00); pmw3901_write_reg(0x7F, 0x05); pmw3901_write_reg(0x41, 0xB3);
	pmw3901_write_reg(0x43, 0xF1); pmw3901_write_reg(0x45, 0x14); pmw3901_write_reg(0x5B, 0x32);
	pmw3901_write_reg(0x5F, 0x34); pmw3901_write_reg(0x7B, 0x08); pmw3901_write_reg(0x7F, 0x06);
	pmw3901_write_reg(0x44, 0x1B); pmw3901_write_reg(0x40, 0xBF); pmw3901_write_reg(0x4E, 0x3F);
	pmw3901_write_reg(0x7F, 0x08); pmw3901_write_reg(0x65, 0x20); pmw3901_write_reg(0x6A, 0x18);
	pmw3901_write_reg(0x7F, 0x09); pmw3901_write_reg(0x4F, 0xAF); pmw3901_write_reg(0x5F, 0x40);
	pmw3901_write_reg(0x48, 0x80); pmw3901_write_reg(0x49, 0x80); pmw3901_write_reg(0x57, 0x77);
	pmw3901_write_reg(0x60, 0x78); pmw3901_write_reg(0x61, 0x78); pmw3901_write_reg(0x62, 0x08);
	pmw3901_write_reg(0x63, 0x50); pmw3901_write_reg(0x7F, 0x0A); pmw3901_write_reg(0x45, 0x60);
	pmw3901_write_reg(0x7F, 0x00); pmw3901_write_reg(0x4D, 0x11); pmw3901_write_reg(0x55, 0x80);
	pmw3901_write_reg(0x74, 0x1F); pmw3901_write_reg(0x75, 0x1F); pmw3901_write_reg(0x4A, 0x78);
	pmw3901_write_reg(0x4B, 0x78); pmw3901_write_reg(0x44, 0x08); pmw3901_write_reg(0x45, 0x50);
	pmw3901_write_reg(0x64, 0xFF); pmw3901_write_reg(0x65, 0x1F); pmw3901_write_reg(0x7F, 0x14);
	pmw3901_write_reg(0x65, 0x60); pmw3901_write_reg(0x66, 0x08); pmw3901_write_reg(0x63, 0x78);
	pmw3901_write_reg(0x7F, 0x15); pmw3901_write_reg(0x48, 0x58); pmw3901_write_reg(0x7F, 0x07);
	pmw3901_write_reg(0x41, 0x0D); pmw3901_write_reg(0x43, 0x14); pmw3901_write_reg(0x4B, 0x0E);
	pmw3901_write_reg(0x45, 0x0F); pmw3901_write_reg(0x44, 0x42); pmw3901_write_reg(0x4C, 0x80);
	pmw3901_write_reg(0x7F, 0x10); pmw3901_write_reg(0x5B, 0x02); pmw3901_write_reg(0x7F, 0x07);
	pmw3901_write_reg(0x40, 0x41); pmw3901_write_reg(0x70, 0x00); HAL_Delay(10);
	pmw3901_write_reg(0x32, 0x44); pmw3901_write_reg(0x7F, 0x07); pmw3901_write_reg(0x40, 0x40);
	pmw3901_write_reg(0x7F, 0x06); pmw3901_write_reg(0x62, 0xF0); pmw3901_write_reg(0x63, 0x00);
	pmw3901_write_reg(0x7F, 0x0D); pmw3901_write_reg(0x48, 0xC0); pmw3901_write_reg(0x6F, 0xD5);
	pmw3901_write_reg(0x7F, 0x00); pmw3901_write_reg(0x5B, 0xA0); pmw3901_write_reg(0x4E, 0xA8);
	pmw3901_write_reg(0x5A, 0x50); pmw3901_write_reg(0x40, 0x80);
}

uint8_t PMW3901_Init(void){
	//Reset Hardware (PA3)
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_Delay(10);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
	HAL_Delay(20);

	CS_HIGH();	HAL_Delay(1);
	CS_LOW();	HAL_Delay(1); CS_HIGH(); HAL_Delay(1);

	pmw3901_write_reg(0x3A, 0x5A); HAL_Delay(5);

	pmw3901_read_reg(0x02); pmw3901_read_reg(0x03);
	pmw3901_read_reg(0x04); pmw3901_read_reg(0x05); pmw3901_read_reg(0x06);

	uint8_t chip_id = pmw3901_read_reg(0x00);
	if(chip_id != 0x49) return 99;

	pmw3901_secret_init();

	pmw3901_read_reg(0x02); pmw3901_read_reg(0x03); pmw3901_read_reg(0x04);
	pmw3901_read_reg(0x05); pmw3901_read_reg(0x06);

	return 0;
}


void PMW3901_Read(PMW3901_Result_t *result){
	uint8_t motion = pmw3901_read_reg(0x02);
	result->squal = pmw3901_read_reg(0x07);
	result->is_valid = 1;

	if(motion & 0x80){ //co chuyen dong
		uint8_t xl = pmw3901_read_reg(0x03);
		uint8_t xh = pmw3901_read_reg(0x04);
		uint8_t yl = pmw3901_read_reg(0x05);
		uint8_t yh = pmw3901_read_reg(0x06);

		result->deltaX = (int16_t)((xh << 8) | xl);
		result->deltaY = (int16_t)((yh << 8) | yl);
	} else {
		result->deltaX = 0;
		result->deltaY = 0;
	}
}

















