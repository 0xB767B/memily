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

INCLUDE(CMakeForceCompiler)

if(NOT TARGET_TRIPLET)
  set(TARGET_TRIPLET "arm-none-eabi")
  message(STATUS "No TARGET_TRIPLET specified, using default: " ${TARGET_TRIPLET})
endif()

# find compiler if it is in path
find_path(TOOLCHAIN_PREFIX ${TARGET_TRIPLET}-gcc)

if("${TOOLCHAIN_PREFIX}" MATCHES ".*-NOTFOUND.*")
  message(FATAL_ERROR " ------- No compiler found! Provide path to compiler via TOOLCHAIN_PREFIX -------")
else()
  # strip bin from toolchain-prefix
  string(REGEX REPLACE "/bin$" "" TOOLCHAIN_PREFIX ${TOOLCHAIN_PREFIX})
endif()

set(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_PREFIX}/bin)
# todo what is TOOLCHAIN_INC_DIR needed for?
set(TOOLCHAIN_INC_DIR ${TOOLCHAIN_PREFIX}/${TARGET_TRIPLET}/include)
# todo what is TOOLCHAIN_LIB_DIR needed for?
set(TOOLCHAIN_LIB_DIR ${TOOLCHAIN_PREFIX}/${TARGET_TRIPLET}/lib)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

CMAKE_FORCE_C_COMPILER(${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-g++ GNU)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-gcc) # memily should not contain any asm-files
set(CMAKE_OBJCOPY ${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-objcopy CACHE INTERNAL "objcopy tool")
set(CMAKE_OBJCOPY ${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-objdump CACHE INTERNAL "objdump tool")

set(CMAKE_C_FLAGS_DEBUG "-mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -std=gnu11" CACHE INTERNAL "c compiler flags debug") # -MMD -MP -MF"system/src/stm32f1-stdperiph/stm32f10x_gpio.d" -MT"system/src/stm32f1-stdperiph/stm32f10x_gpio.o" -c -o "system/src/stm32f1-stdperiph/stm32f10x_gpio.o"
set(CMAKE_CXX_FLAGS_DEBUG "-mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -std=c++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics" CACHE INTERNAL "cxx compiler flags debug") # -MMD -MP -MF"src/BlinkLed.d" -MT"src/BlinkLed.o" -c -o "src/BlinkLed.o"
set(CMAKE_ASM_FLAGS_DEBUG "-mthumb -mcpu=cortex-m3 -g" CACHE INTERNAL "asm compiler flags debug")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "" CACHE INTERNAL "linker flags debug")

set(CMAKE_C_FLAGS_RELEASE "-mthumb -mcpu=cortex-m3 -std=gnu99 -Os -flto" CACHE INTERNAL "c compiler flags release")
set(CMAKE_CXX_FLAGS_RELEASE "-mthumb -mcpu=cortex-m3 -std=c++11 -Os -flto" CACHE INTERNAL "cxx compiler flags release")
set(CMAKE_ASM_FLAGS_RELEASE "" CACHE INTERNAL "asm compiler flags release")
set(CMAKE_EXE_LINKER_FLAGS_RELESE "-flto" CACHE INTERNAL "linker flags release")

set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_PREFIX}/${TARGET_TRIPLET} ${EXTRA_FIND_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(MY_MAP_FILE_NAME "xyz.map")

set(CMAKE_EXE_LINKER_FLAGS "-T${PROJECT_SOURCE_DIR}/target/mcu/st/stm32f103rb/stm32f103rb.ld -nostartfiles -Xlinker --gc-sections --specs=nano.specs -Wl,-Map,${MY_MAP_FILE_NAME}" CACHE INTERNAL "executable linker flags")
set(CMAKE_MODULE_LINKER_FLAGS "-mthumb -mcpu=cortex-m3 -mabi=aapcs" CACHE INTERNAL "module linker flags")


