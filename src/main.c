#include <stdio.h>

#include "hardware/i2c.h"
#include "pico/stdlib.h"

typedef struct {
  i2c_inst_t* i2c;
  int device_address;
  int sda_pin;
  int scl_pin;
} ADXL345I2C;

const struct {
  const uint8_t ID_REGISTER_ADDR;
  const uint8_t DEVICE_ID;
} ADXL345Registers = {0x00, 0xE5};

void setup_i2c(ADXL345I2C* i2c) {
  i2c_init(i2c->i2c, 100000);

  gpio_set_function(i2c->sda_pin, GPIO_FUNC_I2C);
  gpio_pull_up(i2c->sda_pin);

  gpio_set_function(i2c->scl_pin, GPIO_FUNC_I2C);
  gpio_pull_up(i2c->scl_pin);
}

bool check_connection(ADXL345I2C* i2c) {
  uint8_t buf = 0x00;

  i2c_write_blocking(i2c->i2c, i2c->device_address,
                     &ADXL345Registers.ID_REGISTER_ADDR, 1, true);
  i2c_read_blocking(i2c->i2c, i2c->device_address, &buf, 1, false);

  return buf == ADXL345Registers.DEVICE_ID;
}

int main() {
  stdio_init_all();

  ADXL345I2C adxl345_i2c = {i2c0, 0x53, 0, 1};

  setup_i2c(&adxl345_i2c);
  sleep_ms(250);

  while (true) {
    bool connected = check_connection(&adxl345_i2c);

    printf("connected: %d\n", connected);

    sleep_ms(1000);
  }
}