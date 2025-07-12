cmake_minimum_required(VERSION 3.28.1)

target_compile_definitions(${APPLICATION_NAME}
    PRIVATE
        LOG_MODULE_NAME="app"
        MODULE_LOG_LEVEL=LOG_LEVEL_INFO
)

add_subdirectory(Logging)

target_sources(${APPLICATION_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Application.cpp
)
