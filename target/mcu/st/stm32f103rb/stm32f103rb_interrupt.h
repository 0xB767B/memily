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

namespace irq {
  extern "C" {
  void wwdg_irq_handler();
  void pvd_irq_handler();
  void tamper_irq_handler();
  void rtc_irq_handler();
  void flash_irq_handler();
  void rcc_irq_handler();
  void exti0_irq_handler();
  void exti1_irq_handler();
  void exti2_irq_handler();
  void exti3_irq_handler();
  void exti4_irq_handler();
  void dma1_channel1_irq_handler();
  void dma1_channel2_irq_handler();
  void dma1_channel3_irq_handler();
  void dma1_channel4_irq_handler();
  void dma1_channel5_irq_handler();
  void dma1_channel6_irq_handler();
  void dma1_channel7_irq_handler();
  void adc1_2_irq_handler();
  void usb_hp_can1_tx_irq_handler();
  void usb_lp_can1_rx0_irq_handler();
  void can1_rx1_irq_handler();
  void can1_sce_irq_handler();
  void exti9_5_irq_handler();
  void tim1_brk_irq_handler();
  void tim1_up_irq_handler();
  void tim1_trg_com_irq_handler();
  void tim1_cc_irq_handler();
  void tim2_irq_handler();
  void tim3_irq_handler();
  void tim4_irq_handler();
  void i2c1_ev_irq_handler();
  void i2c1_er_irq_handler();
  void i2c2_ev_irq_handler();
  void i2c2_er_irq_handler();
  void spi1_irq_handler();
  void spi2_irq_handler();
  void usart1_irq_handler();
  void usart2_irq_handler();
  void usart3_irq_handler();
  void exti15_10_irq_handler();
  void rtc_alarm_irq_handler();
  void usb_wakeup_irq_handler();
  }
}
