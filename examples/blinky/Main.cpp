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

#include "stm32f103rb_rcc.h"
#include "stm32f103rb_gpio.h"

int main()
{
  static int foo;
  foo = 2;

  using iopaen = stm32f103rb::rcc::apb2enr::iopaen;

  iopaen::write(1);

  using mode = stm32f103rb::gpio<stm32f103rb::gpioa>::pin<5>::mode;
  using cnf = stm32f103rb::gpio<stm32f103rb::gpioa>::pin<5>::cnf;
  using odr = stm32f103rb::gpio<stm32f103rb::gpioa>::pin<5>::odr;

  mode::write(1);
  cnf::write(0);

  while(1) {
	  foo *= foo;

    odr::write(1);
    for(auto i = 0; i < 625000; ++i) {
    }
    odr::write(0);
    for(auto i = 0; i < 625000; ++i) {
    }
  }
}
