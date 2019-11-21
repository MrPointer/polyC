cmake_minimum_required(VERSION 3.12)

project(polyC C CXX)

add_library(polyC STATIC src/Interface.c)
target_include_directories(polyC PUBLIC include)

add_subdirectory(demo)

if (TEST)
    if (UNIT_TEST)
        add_subdirectory(test)
    endif ()
endif ()
