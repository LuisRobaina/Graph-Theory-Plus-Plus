//
// Created by Luis Fabian on 2/5/20.
//

#ifndef GRAPHTHEORY_GRAPH_H
#define GRAPHTHEORY_GRAPH_H

#include <vector>
#include "Vertex.h";


using namespace std;

class Graph {

private:
    int size;
    char type;
    vector<Vertex *> G;
public:
    // D: directed, U: undirected.
    Graph(char type = 'U');

    void add_vertex(int);

    void connect(int, int, double weight = 0);

    char getType();

    Vertex get_vertex(int);

};


#endif //GRAPHTHEORY_GRAPH_H
