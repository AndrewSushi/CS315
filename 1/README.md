# Assignment 1 - Andrew Chan

## Problem 1 - Adjacency Matrix
Write the adjacency list representation and the adjacency matrix for the following tree:

![Tree 1](imgs/tree1.png)
### Adjacency List
```
1 -> 2 -> 3
2 -> 1 -> 4 -> 5
3 -> 1 -> 6 -> 7
4 -> 2
5 -> 2
6 -> 3
7 -> 3
```
### Adjacency Matrix
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
## Problem 2 - BFS and DFS
Demonstrate how the Breadth-First Search (BFS) and the Depth-First Search (DFS) work, respectively. Use the node “q” as the starting node. During the search, when you have multiple choices regarding which node to visit next please use the alphabetical order to choose the next node.
### BFS
q\
~~q~~ s t w\
~~q s~~ t w v\
~~q s t~~ w v x y\
~~q s t w~~ v x y\
~~q s t w v~~ x y\
~~q s t w v x~~ y z\
~~q s t w v x y~~ z\
~~q s t w v x y z~~

### DFS
q\
q s\
q s v\
q s v w\
q s v ~~w~~\
q s ~~v~~\
q ~~s~~\
q t\
q t x\
q t x z\
q t x ~~z~~\
q t ~~x~~\
q t y\
q t ~~y~~\
q ~~t~~\
~~q~~
r
r u
r ~~u~~
~~r~~

## Problem 3 - Butterfiles

We can use DFS to solve this problem. First, we can create an empty graph with n vertices, where each butterfly represents a vertex. We can then seperate the types of butterflies into two sets A and B, and put the nodes into their corresponding set that differenciates the butterfly. 

## Problem 4 - CS Curriculum

We can use topological sort to find the minimum numbers of semesters needed to complete the curriculum. All edges are directed edges from vertex v to vertex w. This means in terms of courses, v is a pre-requisite for course w. It is also worth noting that w can have multiple pre-requisites which means that we have to complete all the v vertices (pre-requisites) before completing w. We can use the following algorithm to find the minimum number of semesters needed to complete the curriculum:
```
1. Do topological sort on the graph, which will result in the linear ordering L of the vertices. 
2. Create an array S of length n is representing the semesters for each of the courses. They should all be defaulted to 0 since we have not found the semesters yet
3. Loop 'i' through each node in L (linear ordering of the graph using topological sort). Then, find the maximum of the semesters in array S. This is to make sure that we have completed all of the pre-requisite courses before. And the reason why we take the maximum, is because we need to finish all of the pre-requisites before taking the current course. We then set the corresponding value to the maximum + 1 in array S. This can be represented as S[i] = max(S) + 1. We add one to the previous max since that is the representation of taking that course after the pre-requisites are finished.
4. After the array S has been completed, the maximum value of the array S will be the minimum number of semesters need to complete the cirriculum. This is because the maximum value represents the most last semester and also corresponds to the end of the curriculum.

This algorithm is O(n + r) where n represents the number of courses needed, and r represents the pre-requisites. Since topological sort is O(n + r) and looping through the total amount of classes is O(n), this algorithm is therefore O(n + r).
```