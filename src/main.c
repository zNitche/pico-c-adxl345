#include <stdio.h>

#include "hardware/i2c.h"
#include "pico/stdlib.h"

#define PICO_DEFAULT_I2C_SDA_PIN 0
#define PICO_DEFAULT_I2C_SCL_PIN 1

#define DEVICE_ADDR _u(0x53)
#define DEVICE_ID_REGISTER_ADDR _u(0x00)
#define DEVICE_ID _u(0xE5)

void setup_i2c() {
  i2c_init(i2c0, 100000);
  gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
  gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
  gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
  gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
}

bool check_connection() {
  uint8_t buf[2];
  uint8_t target_reg[1] = {DEVICE_ID_REGISTER_ADDR};

  i2c_write_blocking(i2c0, DEVICE_ADDR, target_reg, 1, true);
  i2c_read_blocking(i2c0, DEVICE_ADDR, buf, 2, false);

  uint8_t int_buf = *(uint8_t*)buf;

  return int_buf == DEVICE_ID;
}

int main() {
  stdio_init_all();
  setup_i2c();

  sleep_ms(250);

  while (true) {
    bool connected = check_connection();

    printf("connected: %d\n", connected);

    sleep_ms(1000);
  }
}