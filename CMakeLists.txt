cmake_minimum_required(VERSION 3.29.5)
project(stm32g491re VERSION 0.0.1)

set(BOARD_NAME G491RET6)
add_subdirectory(G491RET6)
add_executable(NucleoFw)
target_link_libraries(NucleoFw PRIVATE ${BOARD_NAME})
