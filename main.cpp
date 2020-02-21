#include <iostream>
#include "Utils/Graph.h"

using namespace std;

int main() {

    Graph G;

    G.add_vertex(0);
    G.add_vertex(1);
    G.add_vertex(2);

    G.connect(0, 1, 50);
    G.connect(0, 2);

    return 0;
}