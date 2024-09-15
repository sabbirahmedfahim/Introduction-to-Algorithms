BFS, Dijkstra, and Bellman-Ford are single-source algorithms. However, their time complexity is inefficient for solving the all-pairs shortest path problem, as shown below:

| Algorithm       | Time Complexity     | Notes                                      |
|-----------------|---------------------|--------------------------------------------|
| BFS             | O(V³)               | Does not work on weighted graphs           |
| Dijkstra        | O(V³ * logV)        | Fails with negative weight cycles          |
| Bellman-Ford    | O(V⁴)               | Handles negative weight cycles             |
| Floyd-Warshall  | O(V³)               | Solves all-pairs shortest path             |





That's why the Floyd-Warshall algorithm is used for the **all-pairs shortest path** problem. It can find the shortest distance from any source to any destination. It is considered one of the best solutions for solving all-pairs shortest paths.
