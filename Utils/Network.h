// Network header file:
// A network is a 4 tuple <G,s,t,c> where G is a directed graph, s is
// a distinguished vertex known as the source, t is distinguished vertex knwon as the sink
// and c is a capacity function.
// Created by Luis Fabian on 3/15/20.
//

#ifndef GRAPHTHEORY_NETWORK_H
#define GRAPHTHEORY_NETWORK_H

#include "Graph.h"

class Network {
    private:
    Graph G;
     char id_source;
     char id_sink;

    public:
    /**
     *
     * @param G : A directed graph.
     * @param id_s : The char id of the source vertex in G.
     * @param id_t : The char id of the sink vertex in G.
     * @param capacities : A vector of capacities to be assigned to each directed edge in the graph.
     *                    Defaults to the empty list.
     */
    Network(const Graph & G, const char & id_s, const char &id_t, const std::vector<double> & capacities = {});
    /**
     * Modify the capacity of the edge between the vertices in G with the given
     * @param id_a : char id of the vertex a.
     * @param id_b : char id of the  vertex b.
     */
    void set_capacity(const char & id_a, const char & id_b);
};


#endif //GRAPHTHEORY_NETWORK_H
