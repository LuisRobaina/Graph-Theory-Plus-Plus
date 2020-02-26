//
// Created by Luis Fabian on 2/5/20.
//

#ifndef GRAPHTHEORY_VERTEX_H
#define GRAPHTHEORY_VERTEX_H

#include <string>
#include <vector>

using namespace std;

class Vertex {
private:
  int id;
  char id_char;
  std::string content;
  int adjacency_count;

public:
  // Keeps parallel vectors with adjacent vertices to this vertex and respective
  // weights.
  vector<Vertex> adjacent_vertices;
  vector<double> edge_weight;

  Vertex(int, char, string);

  int getId() const;
  char get_char_id() const;
  std::string get_content() const;

  void addAdj(const Vertex &, double weight = 0);

  bool isAdj(const Vertex &);

  void print_adjacency_bag();

  bool operator==(const Vertex &rhs);
};

#endif // GRAPHTHEORY_VERTEX_H
