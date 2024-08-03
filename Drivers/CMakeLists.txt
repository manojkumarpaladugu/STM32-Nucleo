cmake_minimum_required(VERSION 3.28.1)

set(DRIVERS_LIBRARY Drivers)
add_library(${DRIVERS_LIBRARY} OBJECT)

if (${BOARD} MATCHES "STM32G491xx")
    set(DRIVERS_DIRECTORY "G4")
else()
    message(FATAL_ERROR "Variable 'BOARD' is not defined")
endif()

add_subdirectory(${DRIVERS_DIRECTORY})
