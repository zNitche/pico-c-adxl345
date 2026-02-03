#include <stdbool.h>

#include "hardware/i2c.h"

typedef struct {
  i2c_inst_t* i2c;
  int device_address;
  int sda_pin;
  int scl_pin;
} ADXL345I2C;

typedef struct {
  const uint8_t ID_REGISTER_ADDR;
  const uint8_t DEVICE_ID;
  const uint8_t POWER_CONTROL_REGISTER_ADDR;
  const uint8_t DATA_REGISTER_ADDR;
  const uint8_t DATA_FORMAT_REGISTER_ADDR;
  const uint8_t ACTIVE_MODE;
  const uint8_t STANDBY_MODE;
} ADXL345Registers;

enum ADXL345Ranges {
  RANGE_2G = 0,
  RANGE_4G = 1,
  RANGE_8G = 2,
  RANGE_16G = 3,
};

void adxl345_setup_i2c(ADXL345I2C i2c);
bool adxl345_check_connection(ADXL345I2C i2c);
void adxl345_set_measurements_range(ADXL345I2C i2c_c, enum ADXL345Ranges range);
void adxl345_start_measurements(ADXL345I2C i2c_c);
void adxl345_stop_measurements(ADXL345I2C i2c_c);
void adxl345_get_readings(ADXL345I2C i2c_c, float* accel);
