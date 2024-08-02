cmake_minimum_required(VERSION 3.28.1)

message("-------------------------------------")
message("|            Device Info            |")
message("-------------------------------------")
message("Manufacturer : STMicroelectronics")
message("Board Family : STM32 Nucleo")
message("Board        : ${BOARD}")
message("-------------------------------------\n")

project(STM32-NUCLEO)

add_subdirectory(${BOARD})
