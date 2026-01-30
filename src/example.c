#include <stdio.h>

#include "../lib/pico_adxl345.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"

int main() {
  stdio_init_all();

#ifdef DEBUG
  // waiting for input
  getchar();
#endif

  ADXL345I2C adxl345_i2c = {i2c0, 0x53, 0, 1};

  adxl345_setup_i2c(adxl345_i2c);
  sleep_ms(250);

  while (true) {
    bool connected = adxl345_check_connection(adxl345_i2c);

    printf("connected: %d\n", connected);

    sleep_ms(1000);
  }
}