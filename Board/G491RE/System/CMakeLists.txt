cmake_minimum_required(VERSION 3.28.1)

target_include_directories(${BOARD_LIBRARY} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)

target_sources(${BOARD_LIBRARY} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source/System.cpp)
