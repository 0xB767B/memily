#include "register/reg_t.h"
#include "register/rw_t.h"
#include "register/ro_t.h"
#include "register/wo_t.h"

namespace stm32f103rb {
struct scb
{
   struct mmsr
   {
      static constexpr unsigned addr = 0xe000ed28;
      using mmarvalid = reg_t<rw_t, addr, 7, 1>;
      using mstkerr = reg_t<rw_t, addr, 4, 1>;
      using munstkerr = reg_t<rw_t, addr, 3, 1>;
      using daccviol = reg_t<rw_t, addr, 1, 1>;
      using iaccviol = reg_t<rw_t, addr, 0, 1>;
      using whole = reg_t<rw_t, addr, 0, 8>;
   };

   struct bfsr
   {
      static constexpr unsigned addr = 0xe000ed29;
      using bfarvalid = reg_t<rw_t, addr, 7, 1>;
      using stkerr = reg_t<rw_t, addr, 4, 1>;
      using unstkerr = reg_t<rw_t, addr, 3, 1>;
      using impreciserr = reg_t<rw_t, addr, 2, 1>;
      using preciserr = reg_t<rw_t, addr, 1, 1>;
      using ibuserr = reg_t<rw_t, addr, 0, 1>;
      using whole = reg_t<rw_t, addr, 0, 8>;
   };

   struct ufsr
   {
      static constexpr unsigned addr = 0xe000ed2a;
      using divbyzero = reg_t<rw_t, addr, 9, 1>;
      using unaligned = reg_t<rw_t, addr, 8, 1>;
      using nocp = reg_t<rw_t, addr, 3, 1>;
      using invpc = reg_t<rw_t, addr, 2, 1>;
      using invstate = reg_t<rw_t, addr, 1, 1>;
      using undefinstr = reg_t<rw_t, addr, 0, 1>;
      using whole = reg_t<rw_t, addr, 0, 16>;
   };

   /**
    * hfsr 0xe000ed2c
    * 34.4.3.12 Hard Fault Status Register
    */
   struct hfsr
   {
      static constexpr unsigned addr = 0xe000ed2c;
      using whole = reg_t<rw_t, addr, 0, 32>;
      using debugevt = reg_t<rw_t, addr, 31, 1>;
      using forced = reg_t<rw_t, addr, 30, 1>;
      using vecttbl = reg_t<rw_t, addr, 1, 1>;
   };
};
}
