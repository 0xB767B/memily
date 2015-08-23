set(BLINKY_SOURCES Main.cpp)

include_directories(
    ${MEMILY_INC_DIR}
    ${MCU_DIR} # todo: this is temporary since app should use memily/board include
    )

set(TARGET_NAME "blinky.elf")
add_executable(${TARGET_NAME} ${BLINKY_SOURCES})
target_link_libraries(${TARGET_NAME} ${SYS_LIB_NAME})
