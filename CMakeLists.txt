cmake_minimum_required(VERSION 3.27)

# initialize the SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico-c-adxl345)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(main src/main.c)

target_link_libraries(main pico_stdlib)

pico_enable_stdio_uart(main 0)
pico_enable_stdio_usb(main 1)

pico_add_extra_outputs(main)
