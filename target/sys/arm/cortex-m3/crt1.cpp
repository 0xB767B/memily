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
#include <iterator>

extern "C"
{
  struct ctor_type
  {
    typedef void(*vfp)();
    typedef std::reverse_iterator<const vfp*> const_reverse_iterator;
  };

  extern ctor_type::vfp _ctors_begin[];
  extern ctor_type::vfp _ctors_end[];
}

namespace crt
{
  void init_ctors();
}

void crt::init_ctors()
{
  std::for_each(ctor_type::const_reverse_iterator(_ctors_end),
		        ctor_type::const_reverse_iterator(_ctors_begin),
                [](const ctor_type::vfp ctor){ ctor(); });
}
