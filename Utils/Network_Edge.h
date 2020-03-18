//
// Created by Luis Fabian on 3/15/20.
//

#ifndef GRAPHTHEORY_NETWORK_EDGE_H
#define GRAPHTHEORY_NETWORK_EDGE_H

#include "Edge.h"

class Network_Edge : public Edge {

public:
    double getCapacity() const;

    void setCapacity(double capacity);

    double getFlow() const;

    void setFlow(double flow);

    // Copy constructor.
    Network_Edge(const Edge &e2);

private:
    double capacity;
    double flow;

};


#endif //GRAPHTHEORY_NETWORK_EDGE_H
