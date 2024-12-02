cmake_minimum_required(VERSION 3.30)
project(golp)

set(CMAKE_CXX_STANDARD 20)

add_executable(golp
        main.cpp
        V_Interface.cpp
        V_Interface.h
        V_Console.cpp
        V_Console.h
        V_Graphic.cpp
        V_Graphic.h
        C_Openfile.cpp
        C_Openfile.h
)

