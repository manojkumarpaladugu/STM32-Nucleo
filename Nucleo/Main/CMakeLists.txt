cmake_minimum_required(VERSION 3.29.5)

set(sources
    Source/Main.c
    Source/Syscalls.c
)

target_sources(Nucleo PUBLIC ${sources})
target_include_directories(Nucleo PUBLIC Include)
