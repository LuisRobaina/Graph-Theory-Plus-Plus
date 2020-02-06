//
// Created by Luis Fabian on 2/5/20.
//

#ifndef GRAPHTHEORY_VERTEX_H
#define GRAPHTHEORY_VERTEX_H

#include <vector>

using namespace std;

class Vertex {
private:
    int id;
    int adjacency_count;
    vector<Vertex> adjacent_vertices;
    vector<double> edge_weight;

public:
    Vertex(int);

    int getId() const;

    void addAdj(const Vertex &, double weight = 0);

    bool isAdj(const Vertex &);

    void print_adjacency_bag();

    bool operator==(const Vertex &rhs);
};

#endif //GRAPHTHEORY_VERTEX_H
