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

  bool connected = adxl345_check_connection(adxl345_i2c);

  printf("connected: %d\n", connected);

  enum ADXL345Ranges sensor_range = RANGE_4G;
  adxl345_set_measurements_range(adxl345_i2c, sensor_range);

  adxl345_start_measurements(adxl345_i2c);

  if (connected == true) {
    printf("processing...\n");
    float accel[3] = {0.0};

    while (true) {
      adxl345_get_readings(adxl345_i2c, accel);

      printf("Acc. X = %f, Y = %f, Z = %f\n", accel[0], accel[1], accel[2]);

      sleep_ms(200);
    }

    adxl345_stop_measurements(adxl345_i2c);
  }

  return 0;
}