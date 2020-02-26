# GraphTheory++

A library of C++ code that implements graph theoretical algorithms to be used by projects that require some form of graph structured data.

# How to use it
```
  Create an empty graph (A).
  Graph G('A');

  Add labled vertices to the graph (A).

  G.add_vertex('a');
  G.add_vertex('b');
  G.add_vertex('c');
  G.add_vertex('d');

  Add Edges between vertices and their respective weigth.
  
  G.connect('a','c',10);
  G.connect('b', 'c',20);
  G.connect('c', 'a',3);
  G.connect('d', 'a',4);

  Visualize the graph.
  G.visualize();
```
