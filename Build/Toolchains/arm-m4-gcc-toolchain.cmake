cmake_minimum_required(VERSION 3.29.5)

set(CMAKE_SYSTEM_PROCESSOR cortex-m4)
set(MCPU_FLAGS "-mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
set(CMAKE_EXE_LINKER_FLAGS "-T ${LINKER_SCRIPT} -nostdlib -static --specs=nosys.specs -Wl,--start-group -lc -lm -Wl,--end-group -Wl,--print-memory-usage")
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
