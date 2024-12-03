cmake_minimum_required(VERSION 3.14)
project(Display)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        V_Display.cpp V_Display.h V_Console.cpp V_Console.h V_Graphics.cpp V_Graphics.h)

add_executable(Display ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Display sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
