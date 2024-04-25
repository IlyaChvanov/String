cmake_minimum_required(VERSION 3.27)
project(stringProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(stringProject
        include/MyString.h
        src/main.cpp
        src/MyString.cpp)
