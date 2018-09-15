cmake_minimum_required(VERSION 3.11)

project(LabWork2)

#set(CMAKE_C_STANDARD 11)

set(SOURCES main.c commands.c commands.h)
set(HEADERS commands.h macro.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_subdirectory(LabWork2.Lib)
add_subdirectory(LabWork2.Lib.Tests)

target_link_libraries(${PROJECT_NAME} LabWork2.Lib)