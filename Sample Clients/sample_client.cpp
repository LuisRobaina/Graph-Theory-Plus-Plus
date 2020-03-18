#include "../Algorithms/DijkstrasDistanceAlgorithm.h";
#include "../Utils/Graph.h"
#include "../Utils/Network.h"
#include <iostream>

using namespace std;

int main() {

  // Create an empty directed graph.
  Graph G('A', 'D');

  // Add vertices and edges to the directed graph G.
  G.add_edge('b', 'a', 15);
  G.add_edge('b', 'c', 10);
  G.add_edge('d', 'c', 10);
  G.add_edge('d', 'g', 1);
  G.add_edge('g', 'f', 2);
  G.add_edge('f', 'e', 1);
  G.add_edge('d', 'e', 8);
  G.add_edge('b', 'd', 2);
  G.add_edge('b', 'g', 6);
  G.add_edge('g', 'a', 4);
  G.add_edge('f', 'a', 7);
  G.add_edge('e', 'c', 2);

  G.visualize();

  cout << "Running Dijsktra's Algorithm" << endl;
  map<char, int> distances_map = dijkstras_distances('b', G);

  map<char, int>::iterator itr;

  cout << distances_map.size() << endl;

  for (itr = distances_map.begin(); itr != distances_map.end(); ++itr) {
    cout << "L(" << itr->first << ") = " << itr->second << endl;
  }
  return 0;
}