cmake_minimum_required(VERSION 3.12)

set(PROJECT LabWork2)
project(${PROJECT})

set(CMAKE_C_STANDARD 11)

include_directories(LabWork2.Lib)
include_directories(LabWork2.Lib.Tests)

set(SOURCES main.cpp)

add_executable(LabWork2 ${SOURCES})

add_subdirectory(LabWork2.Lib)
add_subdirectory(LabWork2.Lib.Tests)

target_link_libraries(${PROJECT} LabWork2.Lib)
