cmake_minimum_required(VERSION 3.28.1)

set(DRIVERS_LIBRARY Drivers)
add_library(${DRIVERS_LIBRARY} STATIC)
target_include_directories(${DRIVERS_LIBRARY} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Inc
                                                     ${CMAKE_CURRENT_SOURCE_DIR}/ST/CMSIS/G4/Include
                                                     ${CMAKE_CURRENT_SOURCE_DIR}/ARM/CMSIS/v5/CMSIS/Core/Include
                                                     ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${DRIVERS_LIBRARY} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Src/stm32g4xx_hal.c
                                         ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Src/stm32g4xx_hal_gpio.c
                                         ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Src/stm32g4xx_hal_pwr_ex.c
                                         ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Src/stm32g4xx_hal_rcc.c
                                         ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Src/stm32g4xx_hal_cortex.c
                                         ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Src/stm32g4xx_hal_pwr.c
                                         ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Src/stm32g4xx_hal_uart.c
                                         ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Src/stm32g4xx_hal_uart_ex.c
                                         ${CMAKE_CURRENT_SOURCE_DIR}/ST/Hal/G4/Src/stm32g4xx_hal_dma.c
                                         ${CMAKE_CURRENT_SOURCE_DIR}/ST/CMSIS/G4/Source/Templates/system_stm32g4xx.c)
