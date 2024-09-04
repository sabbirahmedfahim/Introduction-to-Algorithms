BFS - Breadth-First Search
Single source shortest path algorithm
1. traverse
2. level order -> shortest path
3. path printing

In BFS, we need to track visited nodes. Since a binary tree has no cycles, we can freely traverse it without tracking, but in the case of BFS on a graph, **tracking visited nodes is a must** to avoid unnecessary infinite loops