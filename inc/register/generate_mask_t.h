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

#pragma once

#include "register/generate_unshifted_mask_t.h"

/**
 * Generates a bit mask of the given width left shifted
 * offset bits from the least significant bit position of
 * the word.
 * @tparam offset the number of zero bits on the least
 * significant side of the mask
 * @tparam width the number of consecutive one bits in the
 * mask
 */
template<unsigned offset, unsigned width>
struct generate_mask_t {
  enum { value = generate_unshifted_mask_t<width>::value << offset };
};
