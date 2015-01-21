set(MemilySources 
    ./target/arm/cortex-m3/Crt0.cpp
    ./target/arm/cortex-m3/Crt0InitRam.cpp
    ./target/arm/cortex-m3/Crt1.cpp
    ./target/arm/cortex-m3/Exception.cpp
   )

add_library(memily ${MemilySources})