#include "register/reg_t.h"
#include "register/rw_t.h"
#include "register/ro_t.h"
#include "register/wo_t.h"

namespace stm32f103rb {
  enum gpio_name : unsigned int {
    gpioa = 0,
    gpiob,
    gpioc,
    gpiod,
    gpioe,
    gpiof,
    gpiog,
  };

template<gpio_name which_gpio>
struct gpio {
  static constexpr unsigned base_addr = 0x40010800 + 0x400 * which_gpio;
  template <int which_pin>
  struct pin {
    static_assert(0 <= which_pin && which_pin <= 15, "invalid pin");
    static constexpr unsigned addr = base_addr + 0x00;
    using mode = reg_t<rw_t, addr, (which_pin % 8) * 4, 2>;
    using cnf = reg_t<rw_t, addr, (which_pin % 8) * 4 + 2, 2>;
    using idr = reg_t<ro_t, addr + 0x08, which_pin, 1>;
    using odr = reg_t<rw_t, addr + 0x0C, which_pin, 1>;
    using bsr = reg_t<wo_t, addr + 0x10, which_pin, 1>;
    using brr = reg_t<wo_t, addr + 0x14, which_pin, 1>;
    // TODO lckr
  };
};
}
