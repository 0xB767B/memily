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

#include "register/reg_t.h"
#include "register/rw_t.h"
#include "register/ro_t.h"
#include "register/wo_t.h"

namespace stm32f103rb {
struct rcc {
  static constexpr unsigned base_addr = 0x40021000;

  struct cr {
    static constexpr unsigned addr = base_addr + 0x00;
    using pllrdy = reg_t<ro_t, addr, 25, 1>;
    using pllon = reg_t<rw_t, addr, 24, 1>;
    using csson = reg_t<rw_t, addr, 19, 1>;
    using hsebyp = reg_t<rw_t, addr, 18, 1>;
    using hserdy = reg_t<ro_t, addr, 17, 1>;
    using hseon = reg_t<rw_t, addr, 16, 1>;
    using hsical = reg_t<ro_t, addr, 8, 8>;
    using hsitrim = reg_t<rw_t, addr, 3, 5>;
    using hsirdy = reg_t<ro_t, addr, 1, 1>;
    using hsion = reg_t<rw_t, addr, 0, 1>;
    using whole = reg_t<rw_t, addr, 0, 32>;
  };

  struct cfgr {
    static constexpr unsigned addr = base_addr + 0x04;
    // TODO implement
  };

  struct cir {
    static constexpr unsigned addr = base_addr + 0x08;
    // TODO implement
  };

  struct apb2rstr {
    static constexpr unsigned addr = base_addr + 0x0C;
    // TODO implement
  };

  struct apb1rstr {
    static constexpr unsigned addr = base_addr + 0x10;
    // TODO implement
  };

  struct ahbbenr {
    static constexpr unsigned addr = base_addr + 0x14;
    // TODO implement
  };

  struct apb2enr {
    static constexpr unsigned addr = base_addr + 0x18;
    using afioen = reg_t<rw_t, addr, 0, 1>;
    using iopaen = reg_t<rw_t, addr, 2, 1>;
    using iopben = reg_t<rw_t, addr, 3, 1>;
    using iopcen = reg_t<rw_t, addr, 4, 1>;
    using iopden = reg_t<rw_t, addr, 5, 1>;
    using iopeen = reg_t<rw_t, addr, 6, 1>;
    using iopfen = reg_t<rw_t, addr, 7, 1>;
    using iopgen = reg_t<rw_t, addr, 8, 1>;
    using adc1en = reg_t<rw_t, addr, 9, 1>;
    using adc2en = reg_t<rw_t, addr, 10, 1>;
    using tim1en = reg_t<rw_t, addr, 11, 1>;
    using spi1en = reg_t<rw_t, addr, 12, 1>;
    using tim8en = reg_t<rw_t, addr, 13, 1>;
    using usart1en = reg_t<rw_t, addr, 14, 1>;
    using adc3en = reg_t<rw_t, addr, 15, 1>;
    using tim9en = reg_t<rw_t, addr, 19, 1>;
    using tim10en = reg_t<rw_t, addr, 20, 1>;
    using tim11en = reg_t<rw_t, addr, 21, 1>;
    using wholeen = reg_t<rw_t, addr, 0, 32>;
  };

  struct apb1enr {
    static constexpr unsigned addr = base_addr + 0x1C;
    // TODO implement
  };

  struct bdcr {
    static constexpr unsigned addr = base_addr + 0x20;
    // TODO implement
  };

  struct csr {
    static constexpr unsigned addr = base_addr + 0x24;
    // TODO implement
  };
};
}
