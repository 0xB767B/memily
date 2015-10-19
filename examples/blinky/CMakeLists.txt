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

collect_sources(Main.cpp)
#get_property(BLINKY_SOURCES GLOBAL PROPERTY GlobalSourceList)
get_collected_sources(BLINKY_SOURCES)

include_directories(
    ${MCU_DIR} # todo: this is temporary since app should use memily/board include
)

set(TARGET_NAME "blinky.elf")
add_executable(${TARGET_NAME} ${BLINKY_SOURCES})
