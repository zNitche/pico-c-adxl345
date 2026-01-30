#include "pico_adxl345.h"

#include <stdio.h>

#include "hardware/i2c.h"
#include "pico/stdlib.h"

const double EARTH_GRAVITY = 9.80665;
const double SCALE_MULTIPLIER = 0.004;
const double FINAL_READINGS_FACTOR = EARTH_GRAVITY * SCALE_MULTIPLIER;

const ADXL345Registers ADXL345_REGISTERS = {0x00, 0xE5, 0x2D, 0x32,
                                            0x31, 0x28, 0x24};

void write_to_reg(ADXL345I2C i2c_c, uint8_t reg, uint8_t buff) {
  uint8_t write_buff[2] = {reg, buff};

  i2c_write_blocking(i2c_c.i2c, i2c_c.device_address, write_buff,
                     sizeof(write_buff), false);

  sleep_ms(50);
}

void read_from_reg(ADXL345I2C i2c_c, uint8_t reg, int bytes_to_read,
                   uint8_t* buff) {
  i2c_write_blocking(i2c_c.i2c, i2c_c.device_address, &reg, 1, true);
  i2c_read_blocking(i2c_c.i2c, i2c_c.device_address, buff, bytes_to_read,
                    false);
}

void adxl345_setup_i2c(ADXL345I2C i2c_c) {
  i2c_init(i2c_c.i2c, 100000);

  gpio_set_function(i2c_c.sda_pin, GPIO_FUNC_I2C);
  gpio_pull_up(i2c_c.sda_pin);

  gpio_set_function(i2c_c.scl_pin, GPIO_FUNC_I2C);
  gpio_pull_up(i2c_c.scl_pin);
}

bool adxl345_check_connection(ADXL345I2C i2c_c) {
  uint8_t buff = 0x00;

  read_from_reg(i2c_c, ADXL345_REGISTERS.ID_REGISTER_ADDR, 1, &buff);

  return buff == ADXL345_REGISTERS.DEVICE_ID;
}

void adxl345_get_settings(ADXL345I2C i2c_c, uint8_t* buff) {
  read_from_reg(i2c_c, ADXL345_REGISTERS.DATA_FORMAT_REGISTER_ADDR, 1, buff);
}

void adxl345_set_measurements_range(ADXL345I2C i2c_c,
                                    enum ADXL345Ranges range) {
  uint8_t settings_buff = 0b00001000;
  settings_buff += range;

  write_to_reg(i2c_c, ADXL345_REGISTERS.DATA_FORMAT_REGISTER_ADDR,
               settings_buff);
}

void adxl345_start_measurements(ADXL345I2C i2c_c) {
  write_to_reg(i2c_c, ADXL345_REGISTERS.POWER_CONTROL_REGISTER_ADDR,
               ADXL345_REGISTERS.ACTIVE_MODE);
}

void adxl345_stop_measurements(ADXL345I2C i2c_c) {
  write_to_reg(i2c_c, ADXL345_REGISTERS.POWER_CONTROL_REGISTER_ADDR,
               ADXL345_REGISTERS.STANDBY_MODE);
}

void adxl345_get_readings(ADXL345I2C i2c_c) {
  uint16_t data_buff = 0x00;

  read_from_reg(i2c_c, ADXL345_REGISTERS.DATA_REGISTER_ADDR, 6, &data_buff);

  printf("readings -> %d\n", data_buff);
}
