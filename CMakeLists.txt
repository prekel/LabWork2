cmake_minimum_required(VERSION 3.11)

project(LabWork2)

#set(CMAKE_C_STANDARD 11)

set(SOURCES main.c commands.c commands.h options.c)
set(HEADERS commands.h options.h options.c)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_subdirectory(LabWork2.Lib)
add_subdirectory(LabWork2.Lib.Tests)

target_link_libraries(${PROJECT_NAME} LabWork2.Lib)