INCLUDE(CMakeForceCompiler)

if(NOT TOOLCHAIN_PREFIX)
  #set(TOOLCHAIN_PREFIX "/home/borealis/bin/toolchains/arm/gcc-arm-none-eabi-4_9-2014q4")
  set(TOOLCHAIN_PREFIX "/home/sul/bin/toolchains/arm/gcc-arm-none-eabi-4_9-2015q2")
  message(STATUS "No TOOLCHAIN_PREFIX specified, using default: " ${TOOLCHAIN_PREFIX})
endif()

if(NOT TARGET_TRIPLET)
  set(TARGET_TRIPLET "arm-none-eabi")
  message(STATUS "No TARGET_TRIPLET specified, using default: " ${TARGET_TRIPLET})
endif()

set(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_PREFIX}/bin)
#set(TOOLCHAIN_INC_DIR ${TOOLCHAIN_PREFIX}/${TARGET_TRIPLET}/include)
#set(TOOLCHAIN_LIB_DIR ${TOOLCHAIN_PREFIX}/${TARGET_TRIPLET}/lib)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

CMAKE_FORCE_C_COMPILER(${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-g++ GNU)

#set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_PREFIX}/${TARGET_TRIPLET} ${EXTRA_FIND_PATH})
#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_C_FLAGS_DEBUG "-mthumb -mcpu=cortex-m3 -std=gnu99 -Og -g" CACHE INTERNAL "c compiler flags debug")
set(CMAKE_CXX_FLAGS_DEBUG "-mthumb -mcpu=cortex-m3 -std=c++11 -Og -g" CACHE INTERNAL "cxx compiler flags debug")
set(CMAKE_ASM_FLAGS_DEBUG "-mthumb -mcpu=cortex-m3 -g" CACHE INTERNAL "asm compiler flags debug")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "" CACHE INTERNAL "linker flags debug")

set(CMAKE_C_FLAGS_RELEASE "-mthumb -mcpu=cortex-m3 -std=gnu99 -Os -flto" CACHE INTERNAL "c compiler flags release")
set(CMAKE_CXX_FLAGS_RELEASE "-mthumb -mcpu=cortex-m3 -std=c++11 -Os -flto" CACHE INTERNAL "cxx compiler flags release")
set(CMAKE_ASM_FLAGS_RELEASE "" CACHE INTERNAL "asm compiler flags release")
set(CMAKE_EXE_LINKER_FLAGS_RELESE "-flto" CACHE INTERNAL "linker flags release")

#set(CMAKE_C_FLAGS "-mthumb -fno-builtin -mcpu=cortex-m3 -Wall -std=gnu99 -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize" CACHE INTERNAL "c compiler flags")
set(CMAKE_C_FLAGS "-mthumb -fno-builtin -mcpu=cortex-m3 -Wall -std=gnu99 -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize" CACHE INTERNAL "c compiler flags")
#set(CMAKE_CXX_FLAGS "-mthumb -fno-builtin -mcpu=cortex-m3 -Wall -std=c++11 -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize" CACHE INTERNAL "cxx compiler flags")
#set(CMAKE_CXX_FLAGS "-mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wpadded -Wshadow -Wlogical-op -Wfloat-equal -g3 -DDEBUG -DTRACE -DOS_USE_TRACE_SEMIHOSTING_STDOUT -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -Wabi -Wctor-dtor-privacy -Wnoexcept -Wnon-virtual-dtor -Wstrict-null-sentinel -Wsign-promo " CACHE INTERNAL "cxx compiler flags")
#set(CMAKE_ASM_FLAGS "-mthumb -mcpu=cortex-m3" CACHE INTERNAL "asm compiler flags")

#set(CMAKE_EXE_LINKER_FLAGS "-T/home/borealis/git/memily/target/mcu/st/stm32f103rb/stm32f103rb.ld -nostartfiles -Xlinker --gc-sections --specs=nano.specs" CACHE INTERNAL "executable linker flags")
set(CMAKE_EXE_LINKER_FLAGS "-T/home/sul/git/memily/target/mcu/st/stm32f103rb/stm32f103rb.ld -nostartfiles -Xlinker --gc-sections --specs=nano.specs" CACHE INTERNAL "executable linker flags")
set(CMAKE_MODULE_LINKER_FLAGS "-mthumb -mcpu=cortex-m3 -mabi=aapcs" CACHE INTERNAL "module linker flags")
#set(CMAKE_SHARED_LINKER_FLAGS "-mthumb -mcpu=cortex-m3 -mabi=aapcs" CACHE INTERNAL "shared linker flags")


#-T "/home/sul/git/memily/ldscripts/stm32f103rb.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"Memily.map" --specs=nano.specs 
