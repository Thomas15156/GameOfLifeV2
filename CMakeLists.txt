cmake_minimum_required(VERSION 3.30)
project(GameOfLifeV2)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameOfLifeV2 main.cpp M_Grid.cpp M_Grid.h test_view.cpp test_view.h)
