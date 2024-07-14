cmake_minimum_required(VERSION 3.29.5)
project(stm32g491re VERSION 0.0.1)

add_subdirectory(Nucleo)
add_executable(NucleoFw)
target_link_libraries(NucleoFw PRIVATE Nucleo)
