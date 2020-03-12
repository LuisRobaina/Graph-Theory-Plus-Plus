//
// Created by Luis Fabian on 2/5/20.
//

#include "Vertex.h"

using namespace std;

Vertex::Vertex(int id, char id_char, string content) {
  this->id = id;
  this->id_char = id_char;
  this->content = content;
  adjacency_count = 0;
}

// TODO: Update to keep track of vertex id in data struct and not the reference.
void Vertex::addAdj(const Vertex &a, double weight) {

  // Keeps parallel vectors with a reference to vertex a and respective edge
  // weight.
  this->adjacent_vertices.push_back(a);
  this->edge_weight.push_back(weight);
  adjacency_count++;
}

/**
 * @param a - Reference to a vertex a
 * @return True if this vertex is adjacent to the vertex a, false otherwise.
 */
bool Vertex::isAdj(const Vertex &a) {
  for (int i = 0; i < this->adjacency_count; i++) {
    if (this->adjacent_vertices[i] == a) {
      return true;
    }
  }
  return false;
}

int Vertex::getId() const { return id; }
char Vertex::get_char_id() const { return id_char; }

std::string Vertex::get_content() const { return content; }

// Invariant: No two vertices with the same data.
bool Vertex::operator==(const Vertex &rhs) {
  return (this->getId() == rhs.getId());
}