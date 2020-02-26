//
// Created by Luis Fabian on 2/5/20.
// Implements the utilities needed for algorithms on graph-like objects.
//

#include "Graph.h"
#include <iostream>
#include <string>

Graph::Graph(char graph_id, char type) {
  this->type = type;
  this->graph_id = graph_id;
  vertex_count = 0;
  edge_count = 0;
}

char Graph::getType() { return type; }

void Graph::add_vertex(char id_char, string content) {

  // TODO: Validate: No two vertices with same id_char.

  V_G.push_back(new Vertex(vertex_count, id_char, content));
  vertex_count++;
}

Vertex Graph::get_vertex(int id) { return *V_G[id]; }

// Add an edge between two vertices with ids: id_a, id_b.
// weight defaults to zero.

void Graph::connect(const char &id_a, const char &id_b, double weight) {
  //  TODO: Throw exception if vertex is not found.
  int index_a = -1, index_b = -1;

  // Find vertices a and b,
  for (int i = 0; i < vertex_count; i++) {

    if (this->V_G.at(i)->get_char_id() == id_a) {
      index_a = i;
    } else if (this->V_G.at(i)->get_char_id() == id_b) {
      index_b = i;
    }
  }

  // Is this graph directed ?
  if (this->type == 'D') {
    // Directed Graph.
    V_G[index_a]->addAdj(*V_G[index_b], weight);
  } else {
    // If it is an undirected Graph.
    V_G[index_a]->addAdj(*V_G[index_b], weight);
    V_G[index_b]->addAdj(*V_G[index_a], weight);
  }

  E_G.push_back(new Edge(index_a, index_b, weight));
  edge_count++;
}

// Print every edge in the graph as a visual tool.
void Graph::visualize() {

  // Print information about the graph.
  std::cout
      << "Graph Information\n------------------------\nName\t|V(G)|\t|E(G)|"
      << std::endl;
  std::cout << "\t" << this->graph_id << "\t\t" << this->vertex_count << "\t\t"
            << this->edge_count << "\t" << std::endl;
  std::cout << "------------------------" << std::endl;

  for (auto &edge_ptr : E_G) // Access by reference to avoid copying.
  {
    char v_id_a, v_id_b;

    // Identify vertex a.
    v_id_a = V_G[edge_ptr->getIdA()]->get_char_id();

    // Identify type of graph
    std::string arrow = (this->getType() == 'D' ? "-->" : "<-->");

    // Identify vertex b.
    v_id_b = V_G[edge_ptr->getIdB()]->get_char_id();

    std::cout << "(" << v_id_a << ")" << arrow << "(" << v_id_b << ")"
              << std::endl;
  }
}