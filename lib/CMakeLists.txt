cmake_minimum_required(VERSION 3.27)

project(pico_adxl345 VERSION 0.0.1)

add_library(pico_adxl345 INTERFACE)
target_link_libraries(pico_adxl345 INTERFACE
  pico_stdlib
  hardware_i2c
)

target_sources(pico_adxl345 INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/pico_adxl345.c
)
