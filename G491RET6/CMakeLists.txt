cmake_minimum_required(VERSION 3.29.5)

set(EXECUTABLE_NAME "NucleoFirmware")
add_executable(${EXECUTABLE_NAME})
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

add_subdirectory(Startup)
add_subdirectory(Main)
