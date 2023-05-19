# Assignment 5 - Andrew Chan
## Multiplication Matrix Chain

```
p = {5, 10, 3, 12, 5, 50, 6}

M[1, 2] = p[0] * p[1] * p[2] = 5 * 10 * 3 = 150
M[2, 3] = p[1] * p[2] * p[3] = 10 * 3 * 12 = 360
M[3, 4] = p[2] * p[3] * p[4] = 3 * 12 * 5 = 180
M[4, 5] = p[3] * p[4] * p[5] = 12 * 5 * 50 = 3000
M[5, 6] = p[4] * p[5] * p[6] = 5 * 50 * 6 = 1500

M = 
    1   2   3   4   5   6
1|  0   150 0   0   0   0
2|  -   0   360 0   0   0
3|  -   -   0   180 0   0
4|  -   -   -   0   3000 
5|  -   -   -   -   0   1500
6|  -   -   -   -   -   0

M[1,3] = min{M[1,2] + M[3,3] + p0*p2*p3 = 150 + 0 + 180 = 330, 
M[1,1] + M[2,3] + p0*p1*p3 = 0 + 360 + 600 = 960 } = min{330, 960} = 330
M[2,4] = min{M[2,3] + M[4,4] + p1*p3*p4 = 360 + 0 + 600 = 960, 
M[2,2] + M[3,4] + p1*p2*p4 = 0 + 180 + 150 = 330 } = min{960, 330} = 330
M[3,5] = min{M[3,4] + M[5,5] + p2*p4*p5 = 180 + 0 + 750 = 930, 
M[3,3] + M[4,5] + p2*p3*p5 = 0 + 3000 + 1800 = 4800 } = min{930, 4800} = 930 
M[4,6] = min{M[4,5] + M[6,6] + p3*p5*p6 = 3000 + 0 + 3600 = 6600, 
M[4,4] + M[5,6] + p3*p4*p6 = 0 + 1500 + 360 = 1860 } = min{6600, 1860} = 1860

Too many so etc.

Final M:
M = 
    1       2       3       4       5       6
1|  0       150     330     405     1665    2010
2|  -       0       360     330     2430    1950
3|  -       -       0       180     930     1770
4|  -       -       -       0       3000    1860
5|  -       -       -       -       0       1500
6|  -       -       -       -       -       -

The minimum total number of scalar multiplications with dimensions {5, 10, 3, 12, 5, 50, 6} is 2010
```

## 2 - Reliability within Budget
Subproblem:  
The subproblem is to find the maximum reliability that can be achieved with budget B consisting the first `i` stages. We can then define the subproblem as `R(i, B)` where `i` is the current stage, and `B` is the remaining budget.

Base Case:  
The two base cases are:
R(0, B) = 0 for all B. This signifies that there are no stages, which means the reliability is 0.
R(i, 0) = 0 for all i. This signifies that there is no budget, which means that the reliability is 0.

Recurrence:  
`R(i, B) = max{R(i - 1, B), R(i - 1, B - k * c[i]) * (1 - (1 - r[i]) ^ k)} for k = 0 to min{B / c[i], m[i]}`

The first part, `R(i - 1, B - k * c[i])`, represents the maximum reliability for the first `i - 1` stages. This consideres the remaining budget after using k machinges for stage `i`. The second part, `(1 - ( 1 - r[i]) ^ k)`, represents the probability that at least one of the `k` machines for stage `i` works. And `B / c[i]`, represents the maximum number of machines you can buy given the current budget `B`.

## 3 - Destroy Robots
Subproblem:  
The subproblem can be defined as finding the maximum number of robots that can be destroyed with EMP at certain points to the `i`th second. Which means that the maximum number of robots we can destroy considering the robot arrivals and the charging function to the `i`th second. We can define the subproblem as `D(i)`, where `i` represents the current second.

Base Case:  
`D(0) = 0`. This signifies that there are 0 robots that have been destroyed and that have arrived.

Recurrence:  
`D(i) = max{D(i - 1) + min{x[i], f(i - 1)}, min{x[i], f(i)}}`

`D(i - 1)` represents the max robots destroyed up to the `i - 1`th second. `min{x[i], f(i - 1)}` represents the minimum number of robots arriving at the `i`th second, and the max robots destroyed since `f(i - 1)`. When we add the two values together, we get the value of the EMP at the `i - 1`th second. `min{x[i], f(i)}` represents the minimum between the robots arriving at `i`th second, and the max robots that can be destroyed since `f(i)`. This term is using the EMP at second `i`. Then, take the max of the two and that is the max number of robots ddestroyed at second `i`.

Pseudocode:  
```
Function MaxDestroyedRobots(X, f):
    n = length(X)
    D = size (n + 1) array of all 0's

    for i = 1 to n:
        D[i] = max(D[i − 1] + min (X[i], f[i − 1]), min(X[i], f[i]))
    return D[n]
```

`X` represents the sequence of robots arrivials, and `f` is the charding function for the EMP. `MaxDestroyedRobots()` implements a bottom up approach to fill array `D`, where `D[i]` represents the max number of robots destroyed at second `i`. The final value is stored in `D[n]` which is the last second.