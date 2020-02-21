//
// Created by Luis Fabian on 2/5/20.
//
#include "Vertex.h"
#include  <iostream>

using namespace std;

Vertex::Vertex(int id) {
    this->id = id;
    adjacency_count = 0;
}

void Vertex::addAdj(const Vertex &a, double weight) {

    this->adjacent_vertices.push_back(a);
    this->edge_weight.push_back(weight);
    adjacency_count++;
}

bool Vertex::isAdj(const Vertex &a) {
    for (int i = 0; i < this->adjacency_count; i++) {
        if (this->adjacent_vertices[i] == a) {
            return true;
        }
    }
    return false;
}

// For Testing purposes

//void Vertex::print_adjacency_bag() {
//    for (int i = 0; i < adjacency_count; i++) {
//        cout << adjacent_vertices[i].getId() << " at " << &adjacent_vertices[i] << endl;
//    }
//
//}

int Vertex::getId() const {
    return id;
}

// Invariant: No two vertices with the same data.
bool Vertex::operator==(const Vertex &rhs) {
    return (this->getId() == rhs.getId());
}