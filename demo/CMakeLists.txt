cmake_minimum_required(VERSION 3.12)

add_executable(demo polyc_demo.c)
target_link_libraries(demo PRIVATE polyC)
