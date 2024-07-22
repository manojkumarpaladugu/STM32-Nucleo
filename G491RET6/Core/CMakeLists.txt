cmake_minimum_required(VERSION 3.28.1)

target_sources(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source/Main.c
                                          ${CMAKE_CURRENT_SOURCE_DIR}/Source/syscalls.c
                                          ${CMAKE_CURRENT_SOURCE_DIR}/Source/sysmem.c)
