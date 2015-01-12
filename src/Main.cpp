#include "register/stm32f103rb_reg.h"
#include "register/stm32f103rb_rcc.h"
#include "register/stm32f103rb_gpio.h"

int main()
{
  static int foo;
  foo = 2;

  stm32f103rb::rcc::apb2enr::iopaen::write(1);

  stm32f103rb::gpio<0>::crl<5>::mode::write(1);
  stm32f103rb::gpio<0>::crl<5>::cnf::write(0);

  stm32f103rb::gpio<0>::odr<5>::odry::write(1);




  while(1) {
	foo *= foo;
    stm32f103rb::gpio<0>::odr<5>::odry::write(0);
	stm32f103rb::gpio<0>::odr<5>::odry::write(1);
  }
}
