#pragma once

#include "pico_adxl345/types.h"

void _adxl345_write_to_reg(ADXL345I2C i2c_c, uint8_t reg, uint8_t buff);
void _adxl345_read_from_reg(ADXL345I2C i2c_c, uint8_t reg, int bytes_to_read,
                             uint8_t* buff);
void _adxl345_convert_readings(uint8_t raw_buff[6], float* accel);
