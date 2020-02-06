cmake_minimum_required(VERSION 3.15)
project(GraphTheory)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphTheory main.cpp Graph.h Graph.cpp Vertex.h Vertex.cpp)