cmake_minimum_required(VERSION 3.12)

set(PROJECT LabWork2.Lib.Tests)
project(${PROJECT})

set(CMAKE_C_STANDARD 11)

include(GoogleTest)
include_directories(../LabWork2.Lib)

set(SOURCES test.cpp)

add_executable(${PROJECT} ${SOURCES})

enable_testing()
gtest_add_tests(TARGET      ${PROJECT}
        TEST_SUFFIX .noArgs
        )

#add_dependencies(${PROJECT} LabWork2.Lib)
target_link_libraries(${PROJECT} gtest gtest_main)
target_link_libraries(${PROJECT} LabWork2.Lib)
