#pragma once

#include <stdbool.h>

#include "pico_adxl345/types.h"

void adxl345_setup_i2c(ADXL345I2C i2c);
bool adxl345_check_connection(ADXL345I2C i2c);
void adxl345_get_settings(ADXL345I2C i2c_c, uint8_t buff[1]);
void adxl345_set_measurements_range(ADXL345I2C i2c_c, enum ADXL345Ranges range);
void adxl345_start_measurements(ADXL345I2C i2c_c);
void adxl345_stop_measurements(ADXL345I2C i2c_c);
void adxl345_get_readings(ADXL345I2C i2c_c, float accel[3]);
