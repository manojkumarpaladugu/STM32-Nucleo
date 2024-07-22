cmake_minimum_required(VERSION 3.28.1)

add_executable(${EXECUTABLE_NAME})
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

add_subdirectory(Startup)
add_subdirectory(Core)

target_link_libraries(${EXECUTABLE_NAME} Drivers)
