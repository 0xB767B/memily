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

#include "stm32f103rb_interrupt.h"

typedef void (*pvf)();

extern "C" void default_irq_handler();

namespace irq {
  __attribute__ ((section(".irq_vector"),used))
  pvf irq_vector[] = {
      wwdg_irq_handler,
      pvd_irq_handler,
      tamper_irq_handler,
      rtc_irq_handler,
      flash_irq_handler,
      rcc_irq_handler,
      exti0_irq_handler,
      exti1_irq_handler,
      exti2_irq_handler,
      exti3_irq_handler,
      exti4_irq_handler,
      dma1_channel1_irq_handler,
      dma1_channel2_irq_handler,
      dma1_channel3_irq_handler,
      dma1_channel4_irq_handler,
      dma1_channel5_irq_handler,
      dma1_channel6_irq_handler,
      dma1_channel7_irq_handler,
      adc1_2_irq_handler,
      usb_hp_can1_tx_irq_handler,
      usb_lp_can1_rx0_irq_handler,
      can1_rx1_irq_handler,
      can1_sce_irq_handler,
      exti9_5_irq_handler,
      tim1_brk_irq_handler,
      tim1_up_irq_handler,
      tim1_trg_com_irq_handler,
      tim1_cc_irq_handler,
      tim2_irq_handler,
      tim3_irq_handler,
      tim4_irq_handler,
      i2c1_ev_irq_handler,
      i2c1_er_irq_handler,
      i2c2_ev_irq_handler,
      i2c2_er_irq_handler,
      spi1_irq_handler,
      spi2_irq_handler,
      usart1_irq_handler,
      usart2_irq_handler,
      usart3_irq_handler,
      exti15_10_irq_handler,
      rtc_alarm_irq_handler,
      usb_wakeup_irq_handler
  };
}

extern "C" void default_irq_handler()
{
  while (true) {
  }
}

// weak default handlers
#pragma weak wwdg_irq_handler = default_irq_handler
#pragma weak pvd_irq_handler = default_irq_handler
#pragma weak tamper_irq_handler = default_irq_handler
#pragma weak rtc_irq_handler = default_irq_handler
#pragma weak flash_irq_handler = default_irq_handler
#pragma weak rcc_irq_handler = default_irq_handler
#pragma weak exti0_irq_handler = default_irq_handler
#pragma weak exti1_irq_handler = default_irq_handler
#pragma weak exti2_irq_handler = default_irq_handler
#pragma weak exti3_irq_handler = default_irq_handler
#pragma weak exti4_irq_handler = default_irq_handler
#pragma weak dma1_channel1_irq_handler = default_irq_handler
#pragma weak dma1_channel2_irq_handler = default_irq_handler
#pragma weak dma1_channel3_irq_handler = default_irq_handler
#pragma weak dma1_channel4_irq_handler = default_irq_handler
#pragma weak dma1_channel5_irq_handler = default_irq_handler
#pragma weak dma1_channel6_irq_handler = default_irq_handler
#pragma weak dma1_channel7_irq_handler = default_irq_handler
#pragma weak adc1_2_irq_handler = default_irq_handler
#pragma weak usb_hp_can1_tx_irq_handler = default_irq_handler
#pragma weak usb_lp_can1_rx0_irq_handler = default_irq_handler
#pragma weak can1_rx1_irq_handler = default_irq_handler
#pragma weak can1_sce_irq_handler = default_irq_handler
#pragma weak exti9_5_irq_handler = default_irq_handler
#pragma weak tim1_brk_irq_handler = default_irq_handler
#pragma weak tim1_up_irq_handler = default_irq_handler
#pragma weak tim1_trg_com_irq_handler = default_irq_handler
#pragma weak tim1_cc_irq_handler = default_irq_handler
#pragma weak tim2_irq_handler = default_irq_handler
#pragma weak tim3_irq_handler = default_irq_handler
#pragma weak tim4_irq_handler = default_irq_handler
#pragma weak i2c1_ev_irq_handler = default_irq_handler
#pragma weak i2c1_er_irq_handler = default_irq_handler
#pragma weak i2c2_ev_irq_handler = default_irq_handler
#pragma weak i2c2_er_irq_handler = default_irq_handler
#pragma weak spi1_irq_handler = default_irq_handler
#pragma weak spi2_irq_handler = default_irq_handler
#pragma weak usart1_irq_handler = default_irq_handler
#pragma weak usart2_irq_handler = default_irq_handler
#pragma weak usart3_irq_handler = default_irq_handler
#pragma weak exti15_10_irq_handler = default_irq_handler
#pragma weak rtc_alarm_irq_handler = default_irq_handler
#pragma weak usb_wakeup_irq_handler = default_irq_handler
