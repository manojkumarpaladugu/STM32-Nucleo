cmake_minimum_required(VERSION 3.28.1)

set(COMMONS_LIBRARY Commons)
project(${COMMONS_LIBRARY})
add_library(${COMMONS_LIBRARY} INTERFACE)

target_include_directories(${COMMONS_LIBRARY} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_sources(${COMMONS_LIBRARY} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Source/Commons.c)

target_link_libraries(${COMMONS_LIBRARY} INTERFACE)
