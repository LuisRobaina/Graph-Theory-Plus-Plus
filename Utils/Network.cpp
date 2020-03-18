//
// Created by Luis Fabian on 3/15/20.
//
#include "Network.h"
#include "Network_Edge.h"
#include "Edge.h"
#include <iostream>

Network::Network(const Graph &G, const char &id_source, const char &id_sink, const vector<double> &capacities) {
    std::cout<<G.getSize() + "Aquiii " + capacities.size();
    this->G = G;
    this->id_source = id_source;
    this->id_sink = id_sink;

    // Process the edges in G to make them network_edge.
//    if(capacities.size() != 0){
//
//        for(int i = 0; i<G.getSize();i++){
//            Edge *e = G.get_ith_edge(i);
//            e = new Network_Edge(*e);
//            ((Network_Edge *)e)->setCapacity(capacities[i]);
//            std::cout<<"Adding capacity";
//        }
//    }

}

