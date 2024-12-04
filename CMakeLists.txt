cmake_minimum_required(VERSION 3.30)
project(golp)

set(CMAKE_CXX_STANDARD 20)

add_executable(golp
        main.cpp
        V_Interface.cpp
        V_Interface.h
        File.cpp
        File.h
        M_Cell.cpp
        M_Cell.h
        M_Grid.cpp
        M_Grid.h
        test_view.cpp
        test_view.h
)

