cmake_minimum_required(VERSION 3.22.1)
project(SUNY_VM)

# main exe
add_executable(SUNY_VM VM.c)

#link libraries
target_link_libraries(SUNY_VM m)

#add other source files to exe
target_sources(SUNY_VM PRIVATE tape.c)

#include dir for header files
target_include_directories(SUNY_VM PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
