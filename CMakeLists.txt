cmake_minimum_required(VERSION 3.19)

project(PROG4-CS VERSION 1.0)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories( ${PROJECT_SOURCE_DIR}/common)

add_subdirectory(src/CS1-codility)
add_subdirectory(src/CS2-merchant)
