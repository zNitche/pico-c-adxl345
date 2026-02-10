#pragma once

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
    ADXL345_RANGE_2G = 0,
    ADXL345_RANGE_4G = 1,
    ADXL345_RANGE_8G = 2,
    ADXL345_RANGE_16G = 3,
};
