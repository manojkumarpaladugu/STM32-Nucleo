cmake_minimum_required(VERSION 3.28.1)

set(DRIVERS_LIBRARY Drivers)
project(${DRIVERS_LIBRARY})
add_library(${DRIVERS_LIBRARY} INTERFACE)

target_compile_definitions(${DRIVERS_LIBRARY} INTERFACE
    USE_HAL_DRIVER
    ${DEVICE}
    $<$<CONFIG:Debug>:DEBUG>
)

add_subdirectory(${DRIVERS_DIRECTORY})

target_link_libraries(${DRIVERS_LIBRARY} INTERFACE)
