#include "pico_adxl345/adxl345.h"

#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include "pico_adxl345/utils.h"

const ADXL345Registers ADXL345_REGISTERS = {0x00, 0xE5, 0x2D, 0x32,
                                            0x31, 0x28, 0x24};

void adxl345_setup_i2c(ADXL345I2C i2c_c) {
    i2c_init(i2c_c.i2c, 100000);

    gpio_set_function(i2c_c.sda_pin, GPIO_FUNC_I2C);
    gpio_pull_up(i2c_c.sda_pin);

    gpio_set_function(i2c_c.scl_pin, GPIO_FUNC_I2C);
    gpio_pull_up(i2c_c.scl_pin);
}

bool adxl345_check_connection(ADXL345I2C i2c_c) {
    uint8_t buff = 0x00;

    _read_from_reg(i2c_c, ADXL345_REGISTERS.ID_REGISTER_ADDR, 1, &buff);

    return buff == ADXL345_REGISTERS.DEVICE_ID;
}

void adxl345_get_settings(ADXL345I2C i2c_c, uint8_t buff[1]) {
    _read_from_reg(i2c_c, ADXL345_REGISTERS.DATA_FORMAT_REGISTER_ADDR, 1, buff);
}

void adxl345_set_measurements_range(ADXL345I2C i2c_c,
                                    enum ADXL345Ranges range) {
    uint8_t settings_buff = 0b00001000;
    settings_buff += range;

    _write_to_reg(i2c_c, ADXL345_REGISTERS.DATA_FORMAT_REGISTER_ADDR,
                  settings_buff);

    sleep_ms(100);
}

void adxl345_start_measurements(ADXL345I2C i2c_c) {
    _write_to_reg(i2c_c, ADXL345_REGISTERS.POWER_CONTROL_REGISTER_ADDR,
                  ADXL345_REGISTERS.ACTIVE_MODE);

    sleep_ms(100);
}

void adxl345_stop_measurements(ADXL345I2C i2c_c) {
    _write_to_reg(i2c_c, ADXL345_REGISTERS.POWER_CONTROL_REGISTER_ADDR,
                  ADXL345_REGISTERS.STANDBY_MODE);
}

void adxl345_get_readings(ADXL345I2C i2c_c, float accel[3]) {
    uint8_t data_buff[6] = {0};

    _read_from_reg(i2c_c, ADXL345_REGISTERS.DATA_REGISTER_ADDR, 6, &data_buff);
    _convert_readings(data_buff, accel);
};
