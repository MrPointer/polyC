cmake_minimum_required(VERSION 3.6)

add_executable(polyC_unit_tests src/testMain.cpp
        src/action/SingleImplementationActionTests.cpp src/func/SingleImplementationFuncTests.cpp
        src/action/MultiImplementationActionTests.cpp src/func/MultiImplementationFuncTests.cpp
        src/composite/SingleImplementationCompositeTests.cpp
        src/composite/MultiImplementationCompositeTests.cpp)

target_include_directories(polyC_unit_tests PRIVATE include)

target_link_libraries(polyC_unit_tests PRIVATE Catch2::Catch2)
target_include_directories(polyC_unit_tests PRIVATE ../dependencies)
target_link_libraries(polyC_unit_tests PRIVATE polyC)
