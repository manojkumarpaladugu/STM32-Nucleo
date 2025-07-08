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

add_executable(${APPLICATION_NAME})

set(THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty")

add_subdirectory(Modules)
add_subdirectory(Board)
add_subdirectory(Application)

target_link_libraries(${APPLICATION_NAME} PRIVATE Commons ${BOARD_LIBRARY} PRIVATE Drivers)
