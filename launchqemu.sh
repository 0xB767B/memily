#!/bin/bash

pkill qemu-system-arm
qemu-system-arm -cpu cortex-m3 -S -gdb tcp::1234 -nographic -M lm3s6965evb -semihosting -kernel $1

