cmake_minimum_required(VERSION 3.5)

project(navigation)

set (CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/dijkstra.cpp
    src/graph.cpp
    src/Heap.cpp
    src/pair_heap.cpp
    src/fibheap.cpp)

add_executable(navigation ${SOURCES})

SET(CMAKE_BUILD_TYPE "Release")
# SET(CMAKE_BUILD_TYPE "Debug")

target_include_directories(navigation
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

