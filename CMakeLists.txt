project(memily)

cmake_minimum_required(VERSION 2.8.10)

set(CMAKE_VERBOSE_MAKEFILE OFF)

include(${PROJECT_SOURCE_DIR}/cmake/collect_sources.cmake)

set(MEMILY_INC_DIR ${PROJECT_SOURCE_DIR}/inc)

# todo: these variables should be set according to target/board
set(SYS_LIB_DIR ${PROJECT_SOURCE_DIR}/target/sys/arm/cortex-m3)
set(MCU_DIR ${PROJECT_SOURCE_DIR}/target/mcu/st/stm32f103rb)

# the memily-include-directory is needed by all projects using memily
include_directories(
    ${MEMILY_INC_DIR}
    )

add_subdirectory(${SYS_LIB_DIR})
add_subdirectory(${CMAKE_SOURCE_DIR}/examples/blinky)

