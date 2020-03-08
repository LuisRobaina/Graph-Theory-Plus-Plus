//
// Created by Luis Fabian on 2/20/20.
// Implements Dijkstra's Single Source Distance Algorithm.

#ifndef GRAPHTHEORY_DIJKSTRASDISTANCEALGORITHM_H
#define GRAPHTHEORY_DIJKSTRASDISTANCEALGORITHM_H

#include "../Utils/Graph.h";
#include <iterator>
#include <map>

char get_closest_vertex(std::map<char, int> &L) {
  char vertex = ' ';

  std::map<char, int>::iterator itr;
  int shortest_distance = std::numeric_limits<int>::max();

  for (itr = L.begin(); itr != L.end(); ++itr) {
    int d = itr->second;
    if (d < shortest_distance) {
      shortest_distance = d;
      vertex = itr->second;
    }
  }
  return vertex;
}

/**
 *
 * @param source : Single source for dijkstra's algorithm.
 * @param G : Directed Graph.
 * @return : A map with the character ID of each vertex as the key and the
 * distance to it from the source as the value.
 */
std::map<char, int> dijkstras_distances(const char &source, const Graph &G) {
  // TODO: Debug this function.

  // Let L(v) be shortest known distance to the vertex v from vertex source.
  std::map<char, int> L;
  char vertex = source;
  int visited_vertices_count = 1;
  vector<char> visited_vertices;
  /*
   * For each vertex v, other than the source, in G, initialize L(v) =
   * dist(source,v) if there exist and edge source -- v otherwise initialize to
   * infinity.  initialize L(source) = dist(source,source) = 0.
   */
  for (int i = 0; i < G.getOrder(); i++) {

    char v_id = G.get_ith_vertex(i)->getId();
    if (v_id == source) {
      L.insert(pair<char, int>(v_id, 0));
    } else {
      int weight = G.are_connected(source, v_id);
      L.insert(pair<char, int>(
          v_id, weight == 0 ? std::numeric_limits<int>::max() : weight));
    }
  }

  while (visited_vertices_count < G.getOrder()) {

    // Get the vertex with the smallest distance in L.
    vertex = get_closest_vertex(L);
    visited_vertices.push_back(vertex);
    // For every edge adjacent to vertex.
    for (auto &v : G.get_vertex_by_id(vertex)->adjacent_vertices) {

      if (std::find(visited_vertices.begin(), visited_vertices.end(),
                    v.get_char_id()) != visited_vertices.end()) {
        /* visited_vertices contains vertex v */
        continue;
      } else {
        /* visited_vertices does not contain vertex v */
        int w_edge = G.are_connected(vertex, v.get_char_id());
        char v_id = v.getId();

        if (L[v_id] > (L[vertex] + w_edge)) {
          L[v_id] = L[vertex] + w_edge;
        }
      }
    }
    visited_vertices_count++;
  }

  return L;
}

#endif // GRAPHTHEORY_DIJKSTRASDISTANCEALGORITHM_H
