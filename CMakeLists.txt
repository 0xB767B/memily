project(memily)

cmake_minimum_required(VERSION 2.8)

# Turn ON/OFF verbose output
set(CMAKE_VERBOSE_MAKEFILE OFF)

set(SYS_LIB_DIR ${PROJECT_SOURCE_DIR}/target/sys/arm/cortex-m3)
set(SYS_LIB_NAME syscortexm3)

set(MCU_DIR ${PROJECT_SOURCE_DIR}/target/mcu/st/stm32f103rb)


set(MEMILY_INC_DIR ${PROJECT_SOURCE_DIR}/inc)

add_subdirectory(${SYS_LIB_DIR})
add_subdirectory(${CMAKE_SOURCE_DIR}/examples/blinky)

