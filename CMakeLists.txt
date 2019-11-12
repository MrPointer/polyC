cmake_minimum_required(VERSION 3.12)

project(polyC C)

add_library(polyC STATIC src/polyInterface.c)
target_include_directories(polyC PUBLIC include)

add_subdirectory(demo)
