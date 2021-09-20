cmake_minimum_required(VERSION 3.19)
project(cp_template)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE sources RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

foreach(path ${sources})
    get_filename_component(name ${path} NAME)
    add_executable(${name} ${path})
endforeach()