cmake_minimum_required(VERSION 3.11)

project(LabWork2.Lib.Tests)

#set(CMAKE_C_STANDARD 11)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../LabWork2.Lib)

set(SOURCES test.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})


add_test(Tests ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} gtest gtest_main gmock pthread)
target_link_libraries(${PROJECT_NAME} LabWork2.Lib)
