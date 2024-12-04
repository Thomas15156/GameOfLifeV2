cmake_minimum_required(VERSION 3.14)
project(GameOfLifeV2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        M_Cell.h M_Cell.cpp M_Grid.h M_Grid.cpp test_view.h test_view.cpp
        V_Display.cpp V_Display.h V_Console.cpp V_Console.h V_Graphics.cpp V_Graphics.h)

add_executable(GameOfLifeV2 ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(GameOfLifeV2 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
