cmake_minimum_required(VERSION 4.0.2)
project(API_MACRO)

set(CMAKE_CXX_STANDARD 26)

add_executable(API_MACRO main.cpp
        keyboard_api.h
        ios.h
        class_app.h
        debug.h
        mouse_api.h)
