cmake_minimum_required(VERSION 3.29.5)

target_include_directories(${EXECUTABLE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/Drivers/ST/Hal/G4/Inc
                                              ${PROJECT_SOURCE_DIR}/Drivers/ST/CMSIS/G4/Include
                                              ${PROJECT_SOURCE_DIR}/Drivers/ARM/CMSIS/v5/CMSIS/Core/Include)

target_sources(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source/Main.c
                                          ${CMAKE_CURRENT_SOURCE_DIR}/Source/Syscalls.c)
