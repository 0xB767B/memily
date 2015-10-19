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

/**
 * Generates a bit mask of the given width whose least
 * significant bit is at the same bit position as the least
 * significant bit of the word.
 * @tparam width the number of bits in the mask
 */
template <unsigned width>
struct generate_unshifted_mask_t
{
   enum { value = (generate_unshifted_mask_t<width - 1>::value << 1) | 1 };
};

/**
 * Base case.
 */
template <>
struct generate_unshifted_mask_t<0>
{
   enum { value = 0 };
};
