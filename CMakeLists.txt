cmake_minimum_required(VERSION 3.12)

#set(PROJECT LabWork2)
project(LabWork2)

#set(CMAKE_C_STANDARD 11)



#include_directories(LabWork2.Lib)
#include_directories(LabWork2.Lib.Tests)

set(SOURCES main.c)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(LabWork2.Lib)
add_subdirectory(LabWork2.Lib.Tests)

target_link_libraries(${PROJECT_NAME} LabWork2.Lib)
