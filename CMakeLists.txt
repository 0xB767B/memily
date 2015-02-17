project(memily)

cmake_minimum_required(VERSION 2.8)

# Turn ON/OFF verbose output
#set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_TOOLCHAIN_FILE "gcc-STM32.cmake")

message(STATUS "CMAKE_TOOLCHAIN_FILE='${CMAKE_TOOLCHAIN_FILE}'")
message(STATUS "CMAKE_CXX_COMPILER='${CMAKE_CXX_COMPILER}'")


set(MEMILY_INC_DIR ${PROJECT_SOURCE_DIR}/inc)
set(MCU_DIR ${PROJECT_SOURCE_DIR}/target/mcu/st/stm32f103rb)
set(SYS_LIB_DIR ${PROJECT_SOURCE_DIR}/target/sys/arm/cortex-m3)
set(SYS_LIB_NAME syscortexm3)

include_directories(
    ${MEMILY_INC_DIR}
    ${MCU_DIR}
    )


add_subdirectory(${SYS_LIB_DIR})
add_subdirectory(${CMAKE_SOURCE_DIR}/app)