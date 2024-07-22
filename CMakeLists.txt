cmake_minimum_required(VERSION 3.28.1)
project(NucleoFirmware VERSION 0.0.1)

enable_language(C CXX ASM)

add_subdirectory(Drivers)
add_subdirectory(${BOARD_DIRECTORY})
