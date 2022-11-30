cmake_minimum_required(VERSION 3.23)
project(IsBalancedTree)


set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")
add_executable(IsBalancedTree main.cpp)
