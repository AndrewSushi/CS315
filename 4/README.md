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
```
W3:
   1  2  3  4  5  6
1 [0  ∞  ∞  ∞ -1  ∞]
2 [1  0  ∞  2  0  ∞]
3 [3  2  0  4  2 -8]
4 [-4 ∞  ∞  0 -5  ∞]
5 [8  7  ∞  9  0  ∞]
6 [6  5  10 7  5  0]
```
```
W4:
   1  2  3  4  5  6
1 [0  ∞  ∞  ∞ -1  ∞]
2 [-2 0  ∞  2 -3  ∞]
3 [0  2  0  4 -1 -8]
4 [-4 ∞  ∞  0 -5  ∞]
5 [5  7  ∞  9  0  ∞]
6 [3  5  10 7  2  0]
```
```
W5:
   1  2  3  4  5  6
1 [0  6  ∞  8 -1  ∞]
2 [-2 0  ∞  2 -3  ∞]
3 [0  2  0  4 -1 -8]
4 [-4 2  ∞  0 -5  ∞]
5 [5  7  ∞  9  0  ∞]
6 [3  5  10 7  2  0]
```
```
W6:
   1   2  3  4  5  6
1 [0   6  ∞  8 -1  ∞]
2 [-2  0  ∞  2 -3  ∞]
3 [-5 -3  0 -1 -6 -8]
4 [-4  2  ∞  0 -5  ∞]
5 [5   7  ∞  9  0  ∞]
6 [3   5  10 7  2  0]
```
### Final Matrix
```
[0   6  ∞  8 -1  ∞]
[-2  0  ∞  2 -3  ∞]
[-5 -3  0 -1 -6 -8]
[-4  2  ∞  0 -5  ∞]
[5   7  ∞  9  0  ∞]
[3   5  10 7  2  0]
```

## 2 - One-stop car

Subproblem: Define the subproblem C[u, v], as the minimum capacity needed to travel from city 'u' to 'v' with one fuel stop.

Recurrence: To calculate C[u, v], consider all possible intermediate cities 'w' where we could stop to get fuel. The capacity would be the maximum of two cases:
1: The capacity needed to travel from 'u' to 'w', refuel, and then travel from 'w' to 'v'
2: The capacity needed to travel directly from 'u' to 'v' without refueling

We have:
C[u, v] = max{ min{ C[u, w], W*[w, v] } | w ∈ V }.

Where W*[w, v] is the length of the shortest route from city w to v.