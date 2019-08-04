cmake_minimum_required(VERSION 3.14)
project(practice C)

set(CMAKE_C_STANDARD 99)

add_executable(practice readData.c readData.h graph.c graph.h pagerank.c pagerank.h)