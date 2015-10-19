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
 * A write-only mutability policy for use with reg_t.
 */
struct wo_t
{
   static void write(
      volatile unsigned * device,
      unsigned offset,
      unsigned mask,
      unsigned value
   )
   { *device = ((value << offset) & mask); }

   static void set(
      volatile unsigned * device,
      unsigned mask
   )
   { *device = mask; }
};
