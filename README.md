# MEMILY

# Building

    $ cd memily
    $ mkdir build
    $ cd build

Then, to generate the makefiles:

    $ cmake .. -DCMAKE_TOOLCHAIN_FILE=../gcc-STM32.cmake -DCMAKE_BUILD_TYPE=DEBUG

# Debugging

To debug the example using openOCD and the Nucleo-103rb board:

    $ openocd.exe -f board/st_nucleo_f103rb.cfg
    $ arm-none-eabi-gdb blinky.elf

Then in gdb:

    (gdb) target remote localhost:3333
    (gdb) monitor reset halt
    (gdb) load
    (gdb) b main
    (gdb) c
    
Program execution is now stopped at beginning of main.
