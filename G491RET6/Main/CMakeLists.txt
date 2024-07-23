cmake_minimum_required(VERSION 3.28.1)

target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include)

target_sources(${EXECUTABLE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source/Main.c
                                          ${CMAKE_CURRENT_SOURCE_DIR}/Source/syscalls.c
                                          ${CMAKE_CURRENT_SOURCE_DIR}/Source/sysmem.c)
