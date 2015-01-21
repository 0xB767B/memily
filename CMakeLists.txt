project(memily)
cmake_minimum_required(VERSION 2.8)

set(MemilyRootDirectory ${PROJECT_SOURCE_DIR})
set(MemilyIncludeDirectory ${MemilyRootDirectory}/include/)

add_subdirectory(${MemilyRootDirectory}/src)
add_subdirectory(${MemilyRootDirectory}/app)
