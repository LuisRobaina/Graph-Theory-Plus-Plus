cmake_minimum_required(VERSION 3.15)
project(GraphTheory)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphTheory sample_client.cpp Utils/Graph.h Utils/Graph.cpp Utils/Vertex.h Utils/Vertex.cpp Algorithms/DijkstrasDistanceAlgorithm.h Utils/Edge.h)