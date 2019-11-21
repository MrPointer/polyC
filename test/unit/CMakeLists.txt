cmake_minimum_required(VERSION 3.6)

add_executable(polyC_unit_tests testMain.cpp
        src/SingleImplementationTests.cpp)

target_include_directories(polyC_unit_tests PRIVATE include)

target_link_libraries(polyC_unit_tests PRIVATE Catch2::Catch2)
target_include_directories(polyC_unit_tests PRIVATE ../dependencies)
target_link_libraries(polyC_unit_tests PRIVATE polyC)
