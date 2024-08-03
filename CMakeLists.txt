cmake_minimum_required(VERSION 3.28.1)

message("-------------------------------------")
message("|            Device Info            |")
message("-------------------------------------")
message("Manufacturer : STMicroelectronics")
message("Board Family : STM32 Nucleo")
message("Board        : ${BOARD_LIBRARY}")
message("-------------------------------------\n")

project(STM32-NUCLEO)

enable_language(C CXX ASM)

add_executable(${EXECUTABLE_NAME})

add_subdirectory(Board)
add_subdirectory(Application)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${BOARD_LIBRARY} PRIVATE Drivers)
