cmake_minimum_required(VERSION 3.5)

project(navigation)

set (CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/dijkstra.cpp
    src/graph.cpp
    src/input.cpp
    src/Heap.cpp
    src/huffman.cpp)

add_executable(navigation ${SOURCES})

add_definitions(-Wall -g)

target_include_directories(navigation
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

