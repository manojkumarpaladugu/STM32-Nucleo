cmake_minimum_required(VERSION 3.29.5)

set(sources
    Source/Main.c
    Source/Syscalls.c
    Source/Startup.c
)

target_sources(${BOARD_NAME} PUBLIC ${sources})
target_include_directories(${BOARD_NAME} PUBLIC Include)
