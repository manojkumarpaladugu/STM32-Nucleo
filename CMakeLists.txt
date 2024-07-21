cmake_minimum_required(VERSION 3.29.5)
project(STM32Nucleo VERSION 0.0.1)

enable_language(C CXX ASM)

add_compile_definitions(${DEVICE})
add_subdirectory(Drivers)
add_subdirectory(${BOARD_NAME})
