target remote 10.4.13.68:3333
symbol-file blinky.elf
monitor poll on
monitor reset 
#monitor wait 500
#monitor soft_reset_halt
monitor halt

define hook-step
    mon cortex_m3 maskisr on
end
define hookpost-step
    mon cortex_m3 maskisr off
end

define syms
    symbol-file blinky.elf
end

define flash
    #monitor soft_reset_halt
    #monitor reset init
    #monitor halt
    monitor reset halt
    #monitor adapter_khz 600
    #monitor flash write_image blinky.elf
    monitor flash write_image erase unlock ./blinky.bin 0x08000000 bin
    #monitor flash write_image blinky.bin 0x080000 bin
    monitor verify_image ./blinky.bin 0x080000 bin
    symbol-file blinky.elf
    monitor reset init
    #monitor adapter_khz 600
end

define reboot
    monitor reset init
    continue
end


