#include "pico_adxl345/types.h"
#include "pico_adxl345/utils.h"

const double EARTH_GRAVITY = 9.80665;
const double SCALE_MULTIPLIER = 0.004;
const double FINAL_READINGS_FACTOR = EARTH_GRAVITY * SCALE_MULTIPLIER;

void write_to_reg(ADXL345I2C i2c_c, uint8_t reg, uint8_t buff) {
  uint8_t write_buff[2] = {reg, buff};

  i2c_write_blocking(i2c_c.i2c, i2c_c.device_address, write_buff,
                     sizeof(write_buff), false);
}

void read_from_reg(ADXL345I2C i2c_c, uint8_t reg, int bytes_to_read,
                   uint8_t* buff) {
  i2c_write_blocking(i2c_c.i2c, i2c_c.device_address, &reg, 1, true);
  i2c_read_blocking(i2c_c.i2c, i2c_c.device_address, buff, bytes_to_read,
                    false);
}

void convert_readings(uint8_t raw_buff[6], float* accel) {
  for (int i = 0; i < 3; i++) {
    const int data_addr_f = i * 2;
    const int data_addr_n = data_addr_f + 1;

    int16_t out_i =
        (int16_t)(raw_buff[data_addr_f] + (raw_buff[data_addr_n] << 8));
    float out_f = (float)out_i * FINAL_READINGS_FACTOR;

    accel[i] = out_f;
  };
}
