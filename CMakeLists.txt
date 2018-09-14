cmake_minimum_required(VERSION 3.12)

project(LabWork2)

#set(CMAKE_C_STANDARD 11)

set(SOURCES main.c)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(LabWork2.Lib)
add_subdirectory(LabWork2.Lib.Tests)

target_link_libraries(${PROJECT_NAME} LabWork2.Lib)
