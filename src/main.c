#include <stdio.h>

#include "hardware/i2c.h"
#include "pico/stdlib.h"

#define DEVICE_ADDR _u(0x53)
#define DEVICE_ID_REGISTER_ADDR _u(0x00)
#define DEVICE_ID _u(0xE5)

void setup_i2c() {
  i2c_init(i2c0, 100000);

  gpio_set_function(0, GPIO_FUNC_I2C);
  gpio_pull_up(0);

  gpio_set_function(1, GPIO_FUNC_I2C);
  gpio_pull_up(1);
}

bool check_connection() {
  uint8_t buf = 0x00;

  i2c_write_blocking(i2c0, DEVICE_ADDR, DEVICE_ID_REGISTER_ADDR, 1, true);
  i2c_read_blocking(i2c0, DEVICE_ADDR, &buf, 1, false);

  return buf == DEVICE_ID;
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