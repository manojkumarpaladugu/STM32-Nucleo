cmake_minimum_required(VERSION 3.28.1)

enable_language(C CXX ASM)

set(EXECUTABLE_NAME   "NucleoFirmware")
set(DRIVERS_DIRECTORY "G4")
set(DEVICE            "STM32G491xx")

add_executable(${EXECUTABLE_NAME})

add_subdirectory(${PROJECT_SOURCE_DIR}/Drivers ${PROJECT_BINARY_DIR}/Drivers)
add_subdirectory(Main)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE Drivers)
