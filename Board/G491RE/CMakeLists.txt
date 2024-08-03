cmake_minimum_required(VERSION 3.28.1)

set(BOARD             "STM32G491xx")

add_library(${BOARD_LIBRARY} OBJECT)
target_include_directories(${BOARD_LIBRARY} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)

add_subdirectory(${PROJECT_SOURCE_DIR}/Drivers ${PROJECT_BINARY_DIR}/Drivers)
add_subdirectory(Startup)
add_subdirectory(System)

target_link_libraries(${BOARD_LIBRARY} PRIVATE Drivers)
