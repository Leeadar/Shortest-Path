# Shortest-Path

![image](https://user-images.githubusercontent.com/72739568/124129201-3aafba80-da86-11eb-9830-de078130f752.png)


This project is a solution to the problem of finding a minimal path between two vertices.

##### There are three solutions for the problem:

1. Dijkstra’s shortest path algorithm using Minimum Priority Queue
2. Dijkstra’s shortest path algorithm using an unsorted array Priority Queue
3. Bellman–Ford algorithm


##### The graph is implemented in each algorithm in 2 ways:
1. Adjacency Matrix
2. Adjacency List


The input is a file that contains the number of vertices in the graph, the origin vertex, and the destination vertex.
The rest of the file contains a list of edges, origin and destination vertex, and the weight of the edge.

The program prints the weight of the shortest path between the origin vertex to the destintaion vertex

## Time Complexity
 
#### The time complexity analysis of finding a minimal path is as follows:

m = number of edges.

n = number of vertices.

#### Bellman–Ford algorithm
n-1 iteration, and each iteration Relax() is called m times

Thus, Overall time complexity is O(n*m)

#### Dijkstra's algorithm

deleteMin() is called n times.
decreaseKey() is called m times.

Time Complexity depends on the priority queue

If the priority queue is an unsorted array when m= O(n^2)
Time complexity becomes O(n^2).

If the priority queue is a min heap when m = o(n^2)
Time complexity becomes O(mlogn).

If the priority queue is a Fibonacci heap
Time complexity is O(m + nlogn)
