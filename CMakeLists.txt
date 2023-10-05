cmake_minimum_required(VERSION 3.21)
project(Vending_Machine_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Vending_Machine_Cpp main.cpp State.cpp State.h Vend.cpp Vend.h)
