# Assignment 3

## 1 - Minimum Psanning Tree
![MST](imgs/mst.png)  
Consider the graph above. You will be building a Minimum Spanning Tree (MST) for this
graph in two ways. When there is a tie on the edge weights, consider the edges or nodes
in alphabetical order. For example, for an edge, this means (A,F) before (B,C), and (C,D)
before (C,G). Show all intermediate steps, and the set of edges contained in the MST.  
(a) Prim’s method:  

Start a arbitrary node A. Then, we can enqueue all of the edges of A into a priority queue. The priority queue would have in order: the from edge, the to edge, and the weight. Since Prim's algorithm works on an undirected graph, we can say that for each edge, there are two edges that point form one node to the next jsut so we can differntiate visited nodes and unvisited nodes. Then, after we find the minimum weighted edge, we can enqueue those edges from that node and finish until we either find a minimum spanning tree or until we determine that the graph is invalid.  
The intermediate steps should look like this:  
```
Enqueue: A, B, 9 
Enqueue: A, E, 8
Enqueue: A, F, 3
Dequeue: A, F, 3 since it has the lowest weight
Create a path between A to F
Current cost: 3
Enqueue: F, B, 4
Enqueue: F, C, 7
Enqueue: F, G, 5
Enqueue: F, K, 2
Enqueue: F, J, 10
Dequeue: F, K, 2 lowest weight
Create a path between F to K
Current cost: 5
Enqueue: K, G, 5
Enqueue: K, D, 9
Enqueue: K, L, 9
Enqueue: K, J, 3
Dequeue: K, J, 3 lowest weight
Create a path between K and J
Current cost: 8
Enqueue: J, F, 10
Enqueue: J, E, 5
Enqueue: J, I, 12
Dequeue: F, B, 4 lowest weight
Create a path between F to B
Current cost: 12

```

(b) Kruskal’s method:  