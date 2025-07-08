cmake_minimum_required(VERSION 3.28.1)

add_subdirectory(Logging)

target_sources(${APPLICATION_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Application.cpp
)
