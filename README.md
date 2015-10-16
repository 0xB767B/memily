# README

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

## Linker-Script, Startup, etc.

[Understanding the libc_init_array](http://stackoverflow.com/questions/15265295/understanding-the-libc-init-array)

[newlib init.c](http://newlib.sourcearchive.com/documentation/1.18.0/init_8c-source.html)

[Linker and Libraries Guide Initialization and Termination Routines](http://docs.oracle.com/cd/E19683-01/817-1974/6mhlu8fdh/index.html)

[ELF Special Sections](http://refspecs.linuxbase.org/LSB_3.0.0/LSB-PDA/LSB-PDA/specialsections.html)

[Sections](http://www.sco.com/developers/gabi/latest/ch4.sheader.html)

***

# O L D  S T U F F
# README #

This README would normally document whatever steps are necessary to get your application up and running.

### What is this repository for? ###

* Quick summary
* Version
* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

### How do I get set up? ###

* Summary of set up
* Configuration
* Dependencies
* Database configuration
* How to run tests
* Deployment instructions

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

* Repo owner or admin
* Other community or team contact
