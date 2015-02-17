set(SYS_CORTEX_M3_SOURCES 
    Crt0.cpp
    Crt0InitRam.cpp
    Crt1.cpp
    Exception.cpp
   )

#include_directories(
#    ${SYS_LIB_DIR}
#    )

add_library(${SYS_LIB_NAME} ${SYS_CORTEX_M3_SOURCES})