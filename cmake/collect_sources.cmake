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

#
# Functions to handle global source-collecting
# inspired by:
# http://stackoverflow.com/questions/31538466/keeping-file-hierarchy-across-subdirectories-in-cmake
#
# A more sophisticated solution could be found here:
# https://github.com/ruslo/sugar/wiki/Collecting-sources
#

# function collects sources in global property GlobalSourceList
function(collect_sources)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            set(source_abs "${_source}")
        else()
            get_filename_component(_source_abs "${_source}" ABSOLUTE)
        endif()
        set_property(GLOBAL APPEND PROPERTY GlobalSourceList "${_source_abs}")
    endforeach()
endfunction(collect_sources)

# conviniently return collected sources
function(get_collected_sources SOURCES)
    get_property(TEMPORARY GLOBAL PROPERTY GlobalSourceList)
    set(${SOURCES} ${TEMPORARY} PARENT_SCOPE)
endfunction(get_collected_sources)