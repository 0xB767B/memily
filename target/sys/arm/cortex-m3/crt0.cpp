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

namespace crt
{
    void init_ram();
    void init_ctors();
}

extern "C" void reset_handler() __attribute__((used, noinline));
extern "C" int main();

void reset_handler()
{
  // TODO  mcal::cpu::init();
  crt::init_ram();
  // TODO mcal::wdg::secure::trigger();
  crt::init_ctors();
  // TODO mcal::wdg::secure::trigger();

  main(); // call user-main
  while(1); // should never get here! todo: trap, log, hunk, etc.
}
