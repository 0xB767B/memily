/*
 * Memily - Meta Microcontroller Library
 * Copyright (C) 2014 M. Schuler
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <algorithm>
#include <cstddef>

extern "C"
{
  extern std::uintptr_t _rom_data_begin; // start address for the initialization values of the rom-to-ram section
  extern std::uintptr_t _data_begin; // start address for the .data section
  extern std::uintptr_t _data_end; // end address for the .data section
  extern std::uintptr_t _bss_begin; // start address for the .bss section
  extern std::uintptr_t _bss_end; // end address for the .bss section
}

namespace crt
{
  void init_ram();
}

void crt::init_ram()
{
  typedef std::uint32_t memory_aligned_type;

  // copy the data segment initializers from rom to ram
  // note: all data segments are aligned by 4
  const std::size_t size = std::size_t(
          static_cast<const memory_aligned_type*>(static_cast<const void*>(&_data_end))
                                       - static_cast<const memory_aligned_type *>(static_cast<const void*>(&_data_begin)));

  std::copy(static_cast<const memory_aligned_type*>(static_cast<const void*>(&_rom_data_begin)),
            static_cast<const memory_aligned_type*>(static_cast<const void*>(&_rom_data_begin)) + size,
            static_cast<      memory_aligned_type*>(static_cast<      void*>(&_data_begin)));

  // clear  bss segment.
  // note: bss segment is aligned by 4.
  std::fill(static_cast<memory_aligned_type*>(static_cast<void*>(&_bss_begin)),
            static_cast<memory_aligned_type*>(static_cast<void*>(&_bss_end)),
            static_cast<memory_aligned_type>(0U));
}
