#include <iostream>
#include "Graph.h"
using namespace std;
int main() {

    Graph G;

    G.add_vertex(0);
    G.add_vertex(1);
    G.add_vertex(2);

    G.connect(0,1,50);
    G.connect(0,2);

    cout <<G.get_vertex(0).isAdj(G.get_vertex(1));
    cout <<G.get_vertex(0).isAdj(G.get_vertex(2));
    cout <<G.get_vertex(1).isAdj(G.get_vertex(0));
    cout <<G.get_vertex(1).isAdj(G.get_vertex(2));


    return 0;
}