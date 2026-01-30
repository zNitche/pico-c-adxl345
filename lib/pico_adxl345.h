#include <stdbool.h>

#include "hardware/i2c.h"

typedef struct {
  i2c_inst_t* i2c;
  int device_address;
  int sda_pin;
  int scl_pin;
} ADXL345I2C;

enum ADXL345Ranges { RANGE_2G, RANGE_4G, RANGE_8G, RANGE_16G };

void adxl345_setup_i2c(ADXL345I2C i2c);
bool adxl345_check_connection(ADXL345I2C i2c);
void adxl345_set_measurements_range(ADXL345I2C i2c_c, enum ADXL345Ranges range);
void adxl345_start_measurements(ADXL345I2C i2c_c);
void adxl345_stop_measurements(ADXL345I2C i2c_c);
void adxl345_get_readings(ADXL345I2C i2c_c);
