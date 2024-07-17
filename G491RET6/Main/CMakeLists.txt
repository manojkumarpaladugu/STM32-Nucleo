cmake_minimum_required(VERSION 3.29.5)

target_sources(${APPLICATION_NAME} PRIVATE Source/Main.c
                                           Source/Syscalls.c)
target_include_directories(${APPLICATION_NAME} PRIVATE Include)
