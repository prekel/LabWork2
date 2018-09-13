cmake_minimum_required(VERSION 3.12)

set(PROJECT LabWork2.Lib)

project(${PROJECT})

set(CMAKE_C_STANDARD 11)

set(HEADERS functions.h)
set(SOURCES functions.cpp)

add_library(${PROJECT} STATIC ${SOURCES} ${HEADERS})