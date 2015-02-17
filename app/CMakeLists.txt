set(APP_SOURCES Main.cpp)

add_executable(memilyapp ${APP_SOURCES})
target_link_libraries(memilyapp ${SYS_LIB_NAME})
