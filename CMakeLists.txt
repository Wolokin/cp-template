cmake_minimum_required(VERSION 3.16)
project(cp)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE sources RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

foreach(path ${sources})
    string(REPLACE "src/" "" name ${path})
    string(REPLACE "/" "-" name ${name})
    add_executable(${name} ${path})
endforeach()
