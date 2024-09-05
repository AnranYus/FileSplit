cmake_minimum_required(VERSION 3.28)
project(FileSplit)

set(CMAKE_CXX_STANDARD 17)

add_executable(fileSplit main.cpp
        File.cpp
        File.h
)
