set(BLINKY_SOURCES Main.cpp)

include_directories(
    ${MEMILY_INC_DIR}
    ${MCU_DIR} # todo: this is temporary since app should use memily/board include
    )

add_executable(blinky ${BLINKY_SOURCES})
target_link_libraries(blinky ${SYS_LIB_NAME})
