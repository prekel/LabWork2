cmake_minimum_required(VERSION 3.12)

#set(PROJECT LabWork2.Lib)
project(LabWork2.Lib)

#set(CMAKE_C_STANDARD 11)

set(HEADERS functions.h)
set(SOURCES functions.c)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})