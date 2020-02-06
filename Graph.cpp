//
// Created by Luis Fabian on 2/5/20.
//

#include "Graph.h"
#include <iostream>

Graph::Graph(char type) {
    this->type = type;
}

char Graph::getType() {
    return type;
}

void Graph::add_vertex(int id) {
    // Validate: No two vertices with same data.
    G.push_back(new Vertex(id));
}

Vertex Graph::get_vertex(int id) {
    return *G[id];
}

void Graph::connect(int id_a, int id_b, double weight) {
    if (this->type == 'D') {
        // Directed Graph.
        G[id_a]->addAdj(*G[id_b], weight);
        return;
    }
    // Undirected Graph.
    G[id_a]->addAdj(*G[id_b], weight);
    G[id_b]->addAdj(*G[id_a], weight);

}