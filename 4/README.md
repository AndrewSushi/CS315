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

Subproblem: Define the subproblem C[u, v], as the minimum capacity needed to travel from city `u` to `v` with one fuel stop.

Recurrence: To calculate C[u, v], consider all possible intermediate cities `w` where we could stop to get fuel. The capacity would be the maximum of two cases:
1: The capacity needed to travel from `u` to `w`, refuel, and then travel from `w` to `v`
2: The capacity needed to travel directly from `u` to `v` without refueling

We have:
C[u, v] = max{ min{ C[u, w], W*[w, v] } | w ∈ V }.

Where W*[w, v] is the length of the shortest route from city w to v.

## 3 - Sign Placement
Subproblem: Let `dp[i]` represent the minimum penalty for placing signs up to milepost `mi` including `mi`. Find the optimal placement of signs up to milepost `mi` that minimizes penalties. By solving for all mileposts `mi` we can find the solution for the entire highway.

Recurrence:
`dp[i] = min(dp[j] + ((100 - (mi - mj))^2))` 
`for(j = i-1 ; j <= 1; j--)` == `(j = i-1, i-2, ..., 1)`

`dp[j]` represents the minimum penalty for placing signs up to milepost mj. `(100 - (mi - mj))^2` is the penalty for placing signs at mileposts mi and mj. The constraint mi - mj <= 100 makes sure that the signs are placed within the 100-mile requirement.

By iterating through all previous mileposts `(j = i-1, i-2, ..., 1)` and finding the minimum penalty for placing signs at those mileposts combined with the penalty for placing signs at mi and mj, we can determine the minimum penelty for placing signs up to milepost mi `(dp[i])`. We start with a large value for `dp[i]` (we can sat infinity or largest expressed integer) to ensure that the minimum value is selected in the recurrence relation. Then, we can iterate through the mileposts and update the dp array using the recurrence relation. We then eventually reach the last milepost mn, and the minimum penalty for placing signs along the entire road is stored in `dp[n]`, the last element in the array.

## 4 - Real Estate Location
Subproblem: We can define `OPT_<city>(i)` which represents the minimum cost for operation starting at month 1 to `i`, and `city` representing either "Coquille" or "Drain", denoted as `C` or `D`. These are both the two subproblems: `OPT_C(i)` and `OPT_D(i)`  

Recurrence: 
```
OPT_C(i) = c_i + min(OPT_C(i-1), OPT_D(i-1) + M)
OPT_D(i) = d_i + min(OPT_C(i-1) + M, OPT_D(i-1))
```
Where the two base cases are `OPT(1, 'C') = c_1` and `OPT(1, 'D') = d_1`, and c_i and d_i represent the cost of operating each city 'C' and 'D' at month `i`. We can initalize two arrays of size n, `opt_c` and `opt_d` which will store the result of both subproblems. We can then set `opt_c[0] = c_1` and `opt_d[0] = d_1` for the base case. After, we can iterate through the months 2 to n, computing both `opt_c[i]` and `opt_d[i]` using the recurrence relation. Finally, find the minimum cost by doing `min(opt_c[n-1], opt_d[n-1])` since the company is able to end in either city.