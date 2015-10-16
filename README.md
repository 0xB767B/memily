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

# External Information

## The Problem with linking the Sys-Code

* [isr_vectors variable not found when placed inside a static library](http://stackoverflow.com/questions/28949121/isr-vectors-variable-not-found-when-placed-inside-a-static-library)

* [Lost static objects in static libraries with GNU linker ld](http://www.lysium.de/blog/index.php?/archives/222-Lost-static-objects-in-static-libraries-with-GNU-linker-ld.html)

# Markdown

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)
