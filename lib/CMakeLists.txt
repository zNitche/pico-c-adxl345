cmake_minimum_required(VERSION 3.27)

project(pico_adxl345 VERSION 1.2.0)

add_library(pico_adxl345 INTERFACE)

target_link_libraries(pico_adxl345 INTERFACE
  pico_stdlib
  hardware_i2c
)

target_include_directories(pico_adxl345 INTERFACE "${CMAKE_CURRENT_LIST_DIR}/include")

target_sources(pico_adxl345 INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/src/adxl345.c
  ${CMAKE_CURRENT_LIST_DIR}/src/utils.c
)
