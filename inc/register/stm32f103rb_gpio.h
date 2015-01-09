#include "register/reg_t.h"
#include "register/rw_t.h"
#include "register/ro_t.h"
#include "register/wo_t.h"

namespace stm32f103rb {
template<int which>
struct gpio {
  static_assert(0 <= which && which <= 7, "invalid gpio");
  static constexpr unsigned base_addr = 0x40010800 + 0x400 * which;

  template <int name>
  struct crl {
    static_assert(0 <= name && name <= 7, "invalid pin name");
    static constexpr unsigned addr = base_addr + 0x00;
    using mode = reg_t<rw_t, addr, (name % 8) * 4, 2>;
    using cnf = reg_t<rw_t, addr, (name % 8) * 4 + 2, 2>;
    using whole = reg_t<rw_t, addr, 0, 32>;
  };

  template <int name>
  struct crh {
    static_assert(8 <= name && name <= 15, "invalid pin name");
    static constexpr unsigned addr = base_addr + 0x04;
    using mode = reg_t<rw_t, addr, ((name - 8) % 8) * 4, 2>;
    using cnf = reg_t<rw_t, addr, ((name - 8) % 8) * 4 + 2, 2>;
    using whole = reg_t<rw_t, addr, 0, 32>;
  };

  template <int name>
  struct idr {
    static_assert(0 <= name && name <= 15, "invalid pin name");
    static constexpr unsigned addr = base_addr + 0x08;
    using idry = reg_t<ro_t, addr, name, 1>;
    using whole = reg_t<ro_t, addr, 0, 32>;
  };

  template <int name>
  struct odr{
    static_assert(0 <= name && name <= 15, "invalid pin name");
    static constexpr unsigned addr = base_addr + 0x0C;
    using odry = reg_t<rw_t, addr, name, 1>;
    using whole = reg_t<rw_t, addr, 0, 32>;
  };

  template <int name>
  struct bsrr {
    static_assert(0 <= name && name <= 15, "invalid pin name");
    static constexpr unsigned addr = base_addr + 0x10;
    using bsy = reg_t<wo_t, addr, name, 1>;
    using bry = reg_t<wo_t, addr, name + 16, 1>;
    using whole = reg_t<wo_t, addr, 0, 32>;
  };

  template <int name>
  struct brr {
    static_assert(0 <= name && name <= 15, "invalid pin name");
    static constexpr unsigned addr = base_addr + 0x14;
    using bry = reg_t<wo_t, addr, name, 1>;
    using whole = reg_t<wo_t, addr, 0, 32>;
  };

  struct lckr {
    static constexpr unsigned addr = base_addr + 0x18;
    // TODO implement
    using whole = reg_t<rw_t, addr, 0, 32>;
  };
};
}
