collect_sources(Main.cpp)
#get_property(BLINKY_SOURCES GLOBAL PROPERTY GlobalSourceList)
get_collected_sources(BLINKY_SOURCES)

include_directories(
    ${MCU_DIR} # todo: this is temporary since app should use memily/board include
)

message("--------------------------------------------------------------------------------")
message("BLINKY_SOURCES:")
foreach(FILE ${BLINKY_SOURCES})
    message(${FILE})
endforeach()
message("--------------------------------------------------------------------------------")

set(TARGET_NAME "blinky.elf")
add_executable(${TARGET_NAME} ${BLINKY_SOURCES})
