#include "Utils/Graph.h"

using namespace std;

int main() {

  // Create an empty graph.
  Graph G('A');

  // Add vertices to the graph G.

  G.add_vertex('a');
  G.add_vertex('b');
  G.add_vertex('c');
  G.add_vertex('d');

  // Add Edge between vertices.
  G.connect('a','c');
  G.connect('b', 'c');
  G.connect('c', 'a');
  G.connect('d', 'a');

  G.visualize();

  return 0;
}