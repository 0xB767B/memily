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
