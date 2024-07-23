cmake_minimum_required(VERSION 3.28.1)

add_executable(${EXECUTABLE_NAME})

add_subdirectory(Startup)
add_subdirectory(Main)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE Drivers)
