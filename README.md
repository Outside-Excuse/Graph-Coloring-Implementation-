# Graph-Coloring-Implementation-
Based on the Welsh-Powell algorithm, write a C++ program that proposes a solution to the graph coloring problem.

Based on the Welsh-Powell algorithm, write a C++ program that proposes a solution to the graph coloring problem.

Input Format

The input to the program is an undirected graph, in the form of an adjacency matrix. The program receives from the standard input an integers , that describes the number of nodes. Followed by a matrix  with values .

A value of  at position  represents the existence of an arc from node  to node . If there is no arc between node  and node , the value in the matrix is .

Constraints

, followed by a matrix with size  filled with .

Output Format

The output is a list of colors assigned to each node. These colors must be defined as natural numbers starting from 1. If more colors are needed, these must be created and assigned in increasing order.

Sample Input 0

5
0 0 1 0 1
0 0 1 1 1
1 1 0 1 0
0 1 1 0 1
1 1 0 1 0
Sample Output 0

Node: 1, Color: 1
Node: 2, Color: 1
Node: 3, Color: 2
Node: 4, Color: 3
Node: 5, Color: 2
Sample Input 1

6
0 0 0 0 1 0
0 0 1 1 0 1
0 1 0 1 0 0
0 1 1 0 1 1
1 0 0 1 0 0
0 1 0 1 0 0
Sample Output 1

Node: 1, Color: 1
Node: 2, Color: 2
Node: 3, Color: 3
Node: 4, Color: 1
Node: 5, Color: 2
Node: 6, Color: 3
