# GraphTheory++

A library of C++ code that implements graph theoretical algorithms to be used by projects that require some form of graph structured data.

# How to use it.
### This example shows how to create a directed graph.
``` 
  // Include the Algorithm to be used.
  #include "Algorithms/DijkstrasDistanceAlgorithm.h";
  #include "Utils/Graph.h"
  #include <iostream>
```  
### Algorithms supported in Graph-Theory++
```
Dijkstra's Algorithm - Returns the length of the shortest path from a source vertex to every other vertex in the graph.  
```


### Add to your client function:
```
  // Create an empty directed graph A.
  Graph G('A', 'D');
 
  // Add vertices and edges to the directed graph G.
  G.add_edge('b', 'a', 15);
  G.add_edge('b', 'c', 10);
  G.add_edge('d', 'c', 10);
  G.add_edge('d', 'g', 1);
  G.add_edge('g', 'f', 2);
  G.add_edge('f', 'e', 1);
  G.add_edge('d', 'e', 8);
  G.add_edge('b', 'd', 2);
  G.add_edge('b', 'g', 6);
  G.add_edge('g', 'a', 4);
  G.add_edge('f', 'a', 7);
  G.add_edge('e', 'c', 2);
```
## The following graph is created:
![image](https://github.com/LuisRobaina/Graph-Theory-Plus-Plus/blob/master/Images/Sample%20Graph.jpeg)

```
  // Compute the distance from vertex b to every other vertex in G.
  map<char, int> distances_map = dijkstras_distances('b', G);
```
### The result is the length of the shortest path between b and any other vertex in the graph.
```
L(a) = 7
L(b) = 0
L(c) = 8
L(d) = 2
L(e) = 6
L(f) = 5
L(g) = 3
```
