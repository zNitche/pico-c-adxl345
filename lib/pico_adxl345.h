#include <stdbool.h>

#include "hardware/i2c.h"

typedef struct {
  i2c_inst_t* i2c;
  int device_address;
  int sda_pin;
  int scl_pin;
} ADXL345I2C;

void adxl345_setup_i2c(ADXL345I2C i2c);
bool adxl345_check_connection(ADXL345I2C i2c);
