cmake_minimum_required(VERSION 3.15)
project(GraphTheory)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphTheory "Sample Clients/sample_client.cpp" Utils/Graph.h Utils/Graph.cpp Utils/Vertex.h Utils/Vertex.cpp Algorithms/DijkstrasDistanceAlgorithm.h Utils/Edge.h Utils/Network.h Utils/Network_Edge.cpp Utils/Network_Edge.h Utils/Network.cpp "Sample Clients/network_sample_client.cpp")