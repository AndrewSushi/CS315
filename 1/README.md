# Assignment 1 - Andrew Chan

## 1 - Adjacency Matrix
Write the adjacency list representation and the adjacency matrix for the following tree:

![Tree 1](imgs/tree1.png)
```
1 -> 2 -> 3
2 -> 1 -> 4 -> 5
3 -> 1 -> 6 -> 7
4 -> 2
5 -> 2
6 -> 3
7 -> 3
```

```
   1 2 3 4 5 6 7
1 [0 1 1 0 0 0 0]
2 [1 0 0 1 1 0 0]
3 [1 0 0 0 0 1 1]
4 [0 1 0 0 0 0 0]
5 [0 1 0 0 0 0 0]
6 [0 0 1 0 0 0 0]
7 [0 0 1 0 0 0 0]
```