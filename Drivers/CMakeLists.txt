cmake_minimum_required(VERSION 3.28.1)

set(DRIVERS_LIBRARY Drivers)
add_library(${DRIVERS_LIBRARY} OBJECT)

target_compile_definitions(${DRIVERS_LIBRARY} PUBLIC
    USE_HAL_DRIVER
    ${DEVICE}
    $<$<CONFIG:Debug>:DEBUG>
)

add_subdirectory(${DRIVERS_DIRECTORY})
