//
// Created by Luis Fabian on 2/25/20.
//

#ifndef GRAPHTHEORY_EDGE_H
#define GRAPHTHEORY_EDGE_H
#include "Vertex.h"

class Edge {
public:
  Edge(const int a, const int b, const double w) {
    this->id_a = a;
    this->id_b = b;
    this->weight = w;
  }

  int getIdA() const { return id_a; }

  int getIdB() const { return id_b; }

  double getWeight() const { return weight; }

private:
  int id_a;
  int id_b;
  double weight;
};

#endif // GRAPHTHEORY_EDGE_H
