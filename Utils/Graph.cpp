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
  order = 0;
  size = 0;
}
Graph::Graph() {}
char Graph::getType() { return type; }

void Graph::add_vertex(char id_char, string content) {

  // TODO: Assert: No two vertices with same id_char.
  V_G.push_back(new Vertex(order, id_char, content));
  order++;
}

/**
 *
 * @param i : Index of the ith vertex to be retrieved.
 * @return : A pointer to the ith vertex in G or nullptr if  there is no ith
 * vertex in G.
 */

Vertex *Graph::get_ith_vertex(const int &i) const {
  if (i < 0 || i > order) {
    return nullptr;
  }
  return V_G[i];
}

Edge *Graph::get_ith_edge(const int &i) const {
    if (i < 0 || i > order) {
        return nullptr;
    }
    return E_G[i];
}


/**
 *
 * @param id
 * @return
 */

Vertex *Graph::get_vertex_by_id(const char &id) const {
  // TODO: Vertex id not found case.
  for (auto &v : V_G) {
    if (v->get_char_id() == id) {
      return v;
    }
  }
  return nullptr;
}

/**
 * Create an edge between the vertices a and b in the graph.
 * If a or b are not vertices on the graph, creates a new vertex.
 *
 * @param id_a : Character ID of of the vertex  a.
 * @param id_b : Character ID of of the vertex  b.
 * @param weight : Weight  to be assigned to the edge a-b. weight defaults to 1.
 */
void Graph::add_edge(const char &id_a, const char &id_b, double weight) {

  // Assume vertices with IDs id_a and id_b do not exists.
  int index_a = -1, index_b = -1;

  // Try to find vertices with IDs id_a and id_b,
  for (int i = 0; i < order; i++) {

    if (this->V_G.at(i)->get_char_id() == id_a) {
      index_a = i;
    } else if (this->V_G.at(i)->get_char_id() == id_b) {
      index_b = i;
    }
  }
  // If a and/or b were not found then index_a = -1 and/or index_b = -1.
  if (index_a == -1) {
    add_vertex(id_a);
    index_a = V_G.size() - 1;
  }
  if (index_b == -1) {
    add_vertex(id_b);
    index_b = V_G.size() - 1;
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
  size++;
}

/**
 * Prints every edge in the graph, to be used as a visual tool.
 */
void Graph::visualize() {

  // Print information about the graph.
  std::cout
      << "Graph Information\n------------------------\nName\t|V(G)|\t|E(G)|"
      << std::endl;
  std::cout << "\t" << this->graph_id << "\t\t" << this->order << "\t\t"
            << this->size << "\t" << std::endl;
  std::cout << "------------------------" << std::endl;

  for (auto &edge_ptr : E_G) // Access by reference to avoid copying.
  {
    char v_id_a, v_id_b;

    // Identify vertex a.
    v_id_a = V_G[edge_ptr->get_index_a()]->get_char_id();

    // Identify type of graph (Directed or Undirected).
    std::string arrow = (this->getType() == 'D' ? "-->" : "<-->");

    // Identify vertex b.
    v_id_b = V_G[edge_ptr->get_index_b()]->get_char_id();

    // Print the edge.
    std::cout << "(" << v_id_a << ")" << arrow << "(" << v_id_b << ")"
              << std::endl;
  }
}

int Graph::getOrder() const { return order; }
int Graph::getSize() const { return size; }

/**
 * If vertices with id_a and id_b are connected return the weight of the edge
 * between them. Otherwise return zero.
 * @param id_a :
 * @param id_b :
 * @return Weight of the edge between the vertices or 0 if no edge exists.
 */
int Graph::are_connected(const char &id_a, const char &id_b) const {
  for (auto &edge : E_G) {
    int a = edge->get_index_a();
    int b = edge->get_index_b();
    if (V_G[a]->get_char_id() == id_a && V_G[b]->get_char_id() == id_b) {
      // There exists an edge.
      return edge->getWeight();
    }
  }
  return 0;
}