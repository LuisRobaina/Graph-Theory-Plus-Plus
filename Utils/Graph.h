//
// Created by Luis Fabian on 2/5/20.
//

#ifndef GRAPHTHEORY_GRAPH_H
#define GRAPHTHEORY_GRAPH_H

#include "Edge.h"
#include "Vertex.h"
#include <vector>

using namespace std;

class Graph {

protected:
  char graph_id;
  char type;
  vector<Vertex *> V_G;
  vector<Edge *> E_G;
  int order; // Number of vertices.
  int size;  // Number of edges.


public:
  // Convention : D = directed, U = undirected.
  Graph(char graph_id, char type = 'U');
    Graph();
    void add_vertex(char id_char = ' ', string content = "");

  void add_edge(const char &, const char &, double weight = 1);
  Vertex *get_ith_vertex(const int &i) const;
  Vertex *get_vertex_by_id(const char &id) const;
  Edge *get_ith_edge(const int &i) const;
  void visualize();
  char getType();
  int are_connected(const char &id_a, const char &id_b) const;
  int getOrder() const;
  int getSize() const;
};

#endif // GRAPHTHEORY_GRAPH_H
