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


/* Connectors
 *
 * Information from UM1724
 *
 *
 * STMicroelectronics Morpho connector on NUCLEO-F103RB
 *
 *        CN7 odd pins                             CN7 even pins
 * Pin No.      Name                        Pin No.     Name
 *    1         PC10                           2        PC11
 *    3         PC12                           4        PD2
 *    5         VDD                            6        E5V
 *    7         BOOT0 *                        8        GND
 *    9         NC                            10        NC
 *   11         NC                            12        IOREF
 *   13         PA13 ***                      14        RESET
 *   15         PA14 ***                      16        +3V3
 *   17         PA15                          18        +5V
 *   19         GND                           20        GND
 *   21         PB7                           22        GND
 *   23         PC13                          24        VIN
 *   25         PC14                          26        NC
 *   27         PC15                          28        PA0
 *   29         PD0                           30        PA1
 *   31         PD1                           32        PA4
 *   33         VBAT                          34        PB0
 *   35         PC2                           36        PC1 or PB9 ****
 *   37         PC3                           38        PC0 or PB8 ****
 *
 *
 *        CN10 odd pins                            CN10 even pins
 * Pin No.      Name                        Pin No.     Name
 *    1         PC9                            2        PC8
 *    3         PB8                            4        PC6
 *    5         PB9                            6        PC5
 *    7         AVDD                           8        U5V **
 *    9         GND                           10        NC or PD8 ???
 *   11         PA5                           12        PA12
 *   13         PA6                           14        PA11
 *   15         PA7                           16        PB12
 *   17         PB6                           18        PB11
 *   19         PC7                           20        GND
 *   21         PA9                           22        PB2
 *   23         PA8                           24        PB1
 *   25         PB10                          26        PB15
 *   27         PB4                           28        PB14
 *   29         PB5                           30        PB13
 *   31         PB3                           32        AGND
 *   33         PA10                          34        PC4
 *   35         PA2                           36        NC
 *   37         PA3                           38        NC
 *
 *   *    : The default state of BOOT0 is 0. It can be set to 1 when a jumper is
 *          on pin5-7 of CN7.Two unused jumpers are available on CN11 and CN12
 *          (bottom side of the board).
 *
 *   **   : U5V is 5 V power from ST-LINK/V2-1 USB connector and it rises
 *          before +5 V
 *
 *   ***  : PA13 and PA14 share with SWD signals connected to ST-LINK/V2-1, it
 *          is not recommended to use them as IO pins if ST-LINK part is not
 *          cut.
 *
 *   **** : Please refer to Table 9: Solder bridges for detail
 *
 *
 *
 * Arduino connectors on NUCLEO-F103RB
 *
 *
 * CN6 Power (left side)
 *
 * Pin No.          Name          MCU pin         Function
 *    1             NC            -               -
 *    2             IOREF         -               3.3V Ref
 *    3             RESET         NRST            Reset
 *    4             +3V3          -               3.3V input/output
 *    5             +5V           -               5V output
 *    6             GND           -               Ground
 *    7             GND           -               Ground
 *    8             VIN           -               Power input
 *
 *
 *  CN8 Analog (left side)
 *
 * Pin No.          Name          MCU pin         Function
 *    1             A0            PA0             ADC_0
 *    2             A1            PA1             ADC_1
 *    3             A2            PA4             ADC_4
 *    4             A3            PB0             ADC_8
 *    5             A4            PC1 or PB9 *    ADC_11 (PC1) or I2C1_SDA (PB9)
 *    6             A5            PC0 or PB8 *    ADC_10 (PC0) or I2C1_SCL (PB8)
 *
 *
 *  CN5 Digital (right side)
 *
 * Pin No.          Name          MCU pin         Function
 *   10             D15           PB8             I2C1_SCL
 *    9             D14           PB9             I2C1_SDA
 *    8             AREF          -               AVDD
 *    7             GND           -               Ground
 *    6             D13           PA5             SPI_SCK
 *    5             D12           PA6             SPI_MISO
 *    4             D11           PA7             TIM3_CH2 or SPI1_MOSI
 *    3             D10           PB6             TIM4_Ch1 or SPI1_CS
 *    2             D9            PC7             TM3_CH2
 *    1             D8            PA9             -
 *
 *
 *  CN9 Digital (right side)
 *
 * Pin No.          Name          MCU pin         Function
 *    8             D7            PA8             -
 *    7             D6            PB10            TIM2_CH3
 *    6             D5            PB4             TIM3_CH1
 *    5             D4            PB5             -
 *    4             D3            PB3             TIM2_CH2
 *    3             D2            PA10            -
 *    2             D1            PA2             USART2_TX
 *    1             D0            PA3             USART2_RX
 *
 *   *     :Please refer to Table 9: Solder bridges
 *
 */





/*
 */

namespace board {
  enum pin_name : unsigned int {
    // CN7 odd pins
    pc10,
    pc12,
    pa13,
    pa14,
    pa15,
    pb7,
    pc13,
    pc14,
    pc15,
    pd0,
    pd1,
    pc2,
    pc3,
    // CN7 even pins
    pc11,
    pd2,
    pa0,
    pc0,
    pa1,
    pa4,
    pb0,
    pc1,
    pc0,
    // CN10 odd pins
    pc9,
    pb8,
    pb9,
    pa5,
    pa6,
    pa7,
    pb6,
    pc7,
    pa9,
    pa8,
    pb10,
    pb4,
    pb5,
    pb3,
    pa10,
    pa2,
    pa3,
    // CN10 even pins
    pc8,
    pc6,
    pc5,
    pa12,
    pa11,
    pb12,
    pb11,
    pb2,
    pb1,
    pb15,
    pb14,
    pb13,
    pc4
  };




  struct nucleo {
    static void init()
    {
    }

}
}
