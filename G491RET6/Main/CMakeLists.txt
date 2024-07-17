cmake_minimum_required(VERSION 3.29.5)

target_sources(${EXECUTABLE_NAME} PRIVATE Source/Main.c
                                           Source/Syscalls.c)
target_include_directories(${EXECUTABLE_NAME} PRIVATE Include)
