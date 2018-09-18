cmake_minimum_required(VERSION 3.11)

project(LabWork2.Lib)

#set(CMAKE_C_STANDARD 11)

set(HEADERS functions.h)
set(SOURCES functions.c)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

if (UNIX)
	target_link_libraries(${PROJECT_NAME} m)
endif (UNIX)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})