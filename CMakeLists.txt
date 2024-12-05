cmake_minimum_required(VERSION 3.29)
project(GameOfLifeV2)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)
FetchContent_MakeAvailable(SFML)


set(CMAKE_CXX_STANDARD 20)

add_executable(GameOfLifeV2 main.cpp
        File.cpp File.h
        M_Cell.cpp M_Cell.h
        M_Grid.cpp M_Cell.h
        V_Console.cpp V_Console.h
        V_Display.cpp V_Display.h
        V_Graphics.cpp V_Graphics.h
        V_Interface.cpp V_Interface.h)

target_link_libraries(GameOfLifeV2 sfml-graphics)

