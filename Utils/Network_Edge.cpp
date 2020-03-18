//
// Created by Luis Fabian on 3/15/20.
//

#include "Network_Edge.h"

// Copy constructor
Network_Edge::Network_Edge(const Edge &e2){
    this->id_a  = e2.get_index_a();
    id_b  = e2.get_index_b();
    weight = 0;
    flow = 0;
    capacity = 0;
}

double Network_Edge::getCapacity() const {
    return capacity;
}

void Network_Edge::setCapacity(double capacity) {
    this->capacity = capacity;
}

double Network_Edge::getFlow() const {
    return flow;
}

void Network_Edge::setFlow(double flow) {
    this->flow = flow;
}
