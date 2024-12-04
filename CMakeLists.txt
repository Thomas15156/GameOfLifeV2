cmake_minimum_required(VERSION 3.30)
project(golp)

set(CMAKE_CXX_STANDARD 20)

add_executable(golp
        main.cpp
        V_Interface.cpp
        V_Interface.h
        File.cpp
        File.h
)

