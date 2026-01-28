cmake_minimum_required(VERSION 3.27)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico_adxl345_example)

pico_sdk_init()

add_subdirectory(lib)
add_executable(main src/main.c)

target_link_libraries(main pico_stdlib hardware_i2c pico_adxl345)

pico_enable_stdio_uart(main 0)
pico_enable_stdio_usb(main 1)

pico_add_extra_outputs(main)
