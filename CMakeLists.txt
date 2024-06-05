cmake_minimum_required(VERSION 3.28)
project(Ship)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ship main.cpp
        Window.cpp
        Window.h
        Drawer.cpp
        Drawer.h)