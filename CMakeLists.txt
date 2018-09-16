cmake_minimum_required(VERSION 3.11)

project(LabWork2)

#set(CMAKE_C_STANDARD 11)

set(SOURCES commands.c options.c messages.c input.c main.c)
set(HEADERS commands.h options.h messages.h input.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_subdirectory(LabWork2.Lib)
add_subdirectory(LabWork2.Lib.Tests)

target_link_libraries(${PROJECT_NAME} LabWork2.Lib)