# README

# Building

    $ cd memily
    $ mkdir build
    $ cd build

Then, to generate the makefiles:

    $ cmake .. -DCMAKE_TOOLCHAIN_FILE=../gcc-STM32.cmake -DCMAKE_BUILD_TYPE=DEBUG

Or to generate a Eclipse project:

    $ cmake .. -DCMAKE_MODULE_PATH=/home/sul/git/memily/cmake \ 
    -DCMAKE_TOOLCHAIN_FILE=../memily/cmake/gcc-STM32.cmake \
    -DCMAKE_BUILD_TYPE=DEBUG -G"Eclipse CDT4 - Unix Makefiles" \ 
    -DCMAKE_ECLIPSE_EXECUTABLE=/home/sul/git/embcdt/linux/eclipse/eclipse

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
