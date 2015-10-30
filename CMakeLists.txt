#
# Memily - Meta Microcontroller Library
# Copyright (C) 2014 M. Schuler
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 2.8.7)

if(NOT CMAKE_BUILD_TYPE STREQUAL "UNITTEST_HOST")
    if(NOT CMAKE_TOOLCHAIN_FILE)
        message(FATAL_ERROR "You must specifiy a toolchain-file for build type ${CMAKE_BUILD_TYPE}!")
    endif()
else()
    set(CMAKE_C_FLAGS_UNITEST_HOST "-Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -std=gnu11" CACHE INTERNAL "c compiler flags unittest host") # -MMD -MP -MF"system/src/stm32f1-stdperiph/stm32f10x_gpio.d" -MT"system/src/stm32f1-stdperiph/stm32f10x_gpio.o" -c -o "system/src/stm32f1-stdperiph/stm32f10x_gpio.o"
    set(CMAKE_CXX_FLAGS_UNITEST_HOST "-Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -std=c++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics" CACHE INTERNAL "cxx compiler flags unittest host") # -MMD -MP -MF"src/BlinkLed.d" -MT"src/BlinkLed.o" -c -o "src/BlinkLed.o"
    set(CMAKE_ASM_FLAGS_UNITEST_HOST "-g" CACHE INTERNAL "asm compiler flags unittest host")
    set(CMAKE_EXE_LINKER_FLAGS_UNITEST_HOST "" CACHE INTERNAL "linker flags unittest host")
endif()

project(memily)

set(CMAKE_VERBOSE_MAKEFILE OFF)

include(${PROJECT_SOURCE_DIR}/cmake/collect_sources.cmake)

set(MEMILY_INC_DIR ${PROJECT_SOURCE_DIR}/inc)

# the memily-include-directory is needed by all projects using memily
include_directories(
        ${MEMILY_INC_DIR}
)

if(NOT CMAKE_BUILD_TYPE STREQUAL "UNITTEST_HOST")
    # todo: these variables should be set according to target/board
    set(SYS_LIB_DIR ${PROJECT_SOURCE_DIR}/target/sys/arm/cortex-m3)
    set(MCU_DIR ${PROJECT_SOURCE_DIR}/target/mcu/st/stm32f103rb)
    add_subdirectory(${SYS_LIB_DIR})
    add_subdirectory(${MCU_DIR})
    add_subdirectory(${CMAKE_SOURCE_DIR}/examples/blinky)
else()
    include_directories(
            ${PROJECT_SOURCE_DIR}/ext/cpputest/include/}
    )
   add_subdirectory(${PROJECT_SOURCE_DIR}/ext/cpputest)
#    collect_sources(${PROJECT_SOURCE_DIR}/AllTests.cpp)
#    get_collected_sources(UNITTEST_SOURCES)
    set(UNITTEST_SOURCES ${PROJECT_SOURCE_DIR}/test/AllTests.cpp)
    set(TARGET_NAME "alltests")
    add_executable(${TARGET_NAME} ${UNITTEST_SOURCES})
    target_link_libraries(CppUTest)
endif()



