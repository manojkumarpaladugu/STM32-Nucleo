cmake_minimum_required(VERSION 3.28.1)

target_include_directories(${DRIVERS_LIBRARY} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Inc
                                                        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/Device/ST/STM32G4xx/Include
                                                        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/Core/Include
                                                        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Include)

target_sources(${DRIVERS_LIBRARY} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Core/Source/stm32g4xx_it.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Core/Source/stm32g4xx_hal_msp.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_gpio.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_pwr_ex.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_rcc.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_rcc_ex.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_cortex.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_pwr.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_uart.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_uart_ex.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_dma.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Hal/Src/stm32g4xx_hal_uart.c
                                            ${CMAKE_CURRENT_SOURCE_DIR}/Core/Source/system_stm32g4xx.c)