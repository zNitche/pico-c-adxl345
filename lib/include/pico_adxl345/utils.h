#pragma once

void write_to_reg(ADXL345I2C i2c_c, uint8_t reg, uint8_t buff);
void read_from_reg(ADXL345I2C i2c_c, uint8_t reg, int bytes_to_read,
                   uint8_t* buff);
void convert_readings(uint8_t raw_buff[6], float* accel);
