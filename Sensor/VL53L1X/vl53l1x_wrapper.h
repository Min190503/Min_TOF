#ifndef VL53L1X_WRAPPER_H
#define VL53L1X_WRAPPER_H

#include <stdint.h>

//Vl53l1x I2C address
#define TOF_I2C_ADDR	0x52

#define TOF_MODE_SHORT	1		//max 1.3, as manh
#define TOF_MODE_LONG	2		//max 4m as yeu


typedef struct {
	uint16_t distance_mm;		//khoang cach (mm)
	uint16_t signal_rate;		// cuong do tin hieu (kcps)
	uint16_t ambient_rate;		//nhieu ambient (kcps)
	uint8_t  range_status;		//0 = OK, khac 0 = loi
	uint8_t  is_valid;			// 1 = data hop le, 0 = loi
} TOF_Result_t;

/**
 * @brief  Khởi động VL53L1X sensor
 * @return 0=OK, khác 0=lỗi
 */
uint8_t TOF_Init(void);
/**
 * @brief  Đọc khoảng cách (non-blocking check + read)
 * @param  result: con trỏ nhận kết quả
 * @return 0=có data mới, 1=chưa có data, 2+=lỗi
 */
uint8_t TOF_Read(TOF_Result_t *result);
/**
 * @brief  Đọc khoảng cách (blocking - chờ đến khi có data)
 * @param  result: con trỏ nhận kết quả
 * @return 0=OK, khác 0=lỗi
 */
uint8_t TOF_ReadBlocking(TOF_Result_t *result);

#endif
