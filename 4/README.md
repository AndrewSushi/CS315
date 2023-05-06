# Assignment 4 - Andrew Chan

## 1 - Floyd-Warshall Algorithm
Demonstrate the Floyd-Warshall algorithm (i.e., show the series of matrices) on the graph
described by the following weight matrix:
```
W0:
   1  2  3  4  5  6
1 [0  ∞  ∞  ∞ -1  ∞]
2 [1  0  ∞  2  ∞  ∞]
3 [∞  2  0  ∞  ∞ -8]
4 [-4 ∞  ∞  0  3  ∞]
5 [∞  7  ∞  ∞  0  ∞]
6 [∞  5  10 ∞  ∞  0]
```
```
W1:
   1  2  3  4  5  6
1 [0  ∞  ∞  ∞ -1  ∞]
2 [1  0  ∞  2  0  ∞]
3 [∞  2  0  ∞  ∞ -8]
4 [-4 ∞  ∞  0 -5  ∞]
5 [∞  7  ∞  ∞  0  ∞]
6 [∞  5  10 ∞  ∞  0]
```
```
W2:
   1  2  3  4  5  6
1 [0  ∞  ∞  ∞ -1  ∞]
2 [1  0  ∞  2  0  ∞]
3 [3  2  0  4  2 -8]
4 [-4 ∞  ∞  0 -5  ∞]
5 [8  7  ∞  9  0  ∞]
6 [6  5  10 7  5  0]
```