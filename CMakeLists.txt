cmake_minimum_required(VERSION 3.14)
project(practice C)

set(CMAKE_C_STANDARD 99)

add_executable(practice main.c readData.cpp readData.h graph.cpp graph.h)