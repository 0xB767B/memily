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

