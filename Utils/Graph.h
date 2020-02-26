//
// Created by Luis Fabian on 2/5/20.
//

#ifndef GRAPHTHEORY_GRAPH_H
#define GRAPHTHEORY_GRAPH_H

#include "../Algorithms/DijkstrasDistanceAlgorithm.h"
#include "Edge.h"
#include "Vertex.h"
#include <vector>

using namespace std;

class Graph {

private:
  char graph_id;
  int size;
  char type;
  vector<Vertex *> V_G;
  vector<Edge *> E_G;
  int vertex_count;
  int edge_count;

public:
  // Convention = D: directed, U: undirected.
  Graph(char graph_id, char type = 'U');

  void add_vertex(char id_char = ' ', string content = "");

  void connect(const char &, const char &, double weight = 0);

  void visualize();

  char getType();

  Vertex get_vertex(int);
};
#endif // GRAPHTHEORY_GRAPH_H
