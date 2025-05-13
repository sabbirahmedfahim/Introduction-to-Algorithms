#### 📖 Algorithms Quick Reference

This repository contains my personal collection of algorithm codes along with brief notes or core ideas related to each topic. It serves as a quick reference to what I’ve learned and implemented so far.

🔒 Theory Reference: [phitron-book](https://phitron.io/phitron-book/introduction-to-algorithms-01)  
*(Private access required - my theory companion for the algorithm concepts)*  

---
<br>

# Graph Algorithms

## 🗺️ Graph Visualization Tools
- 🔗 [Graph Visual](https://csacademy.com/app/graph_editor)

## 🔄 Graph Representation Methods
- 🔗 [Implementations (adjacency matrix, adjacency list, edge list)](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/tree/main/WEEK_01#readme)
- 🔗 [Conversions between representations](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/tree/main/WEEK_04)

## ❓ When to Use Which Shortest Path Algorithm
- 🔗 [Single Source](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_02/module_7/0_why_bellman_ford_algorithm.markdown)
- 🔗 [All-Pairs](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_02/module_7/3_why_floyd_warshall.markdown)

## 🌲 DFS on Adjacency Lists
- 🔗 [DFS Traversal, Tracking Parents](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_01/module_3/2_dfs.cpp)
- 🔗 [Problem: Building Roads (CSES)](https://cses.fi/problemset/task/1666/) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Building_Roads__DFS.cpp)
- 🔗 [Problem: DFS of graph (GFG)](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/dfs_of_graph__gfg.cpp)

## 📈 BFS on Adjacency Lists
- 🔗 [BFS Traversal, Track Parent & Level](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_01/module_2/12_bfs_shortest_path_printing.cpp) **Shortest Path Printing**
- 🔗 [Problem: BFS of graph (GFG)](https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/bfs_of_graph__gfg.cpp)

## ➡️ Grid Traversal Fundamentals (Direction Array)
- 🔗 [2D Grid Direction Array](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_01/module_3/3_2D_grid.markdown)

## 🌲 DFS on Grids
- 🔗 [Problem: Counting Rooms (CSES)](https://cses.fi/problemset/task/1192) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Counting_Rooms__DFS.cpp)
- 🔗 [Problem: Number of Closed Islands (LeetCode)](https://leetcode.com/problems/number-of-closed-islands/description/) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Number_of_Closed_Islands__LeetCode.cpp)

## 📈 BFS on Grids
- 🔗 [Problem: Counting Rooms (CSES)](https://cses.fi/problemset/task/1192) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Counting_Rooms__BFS.cpp)
- 🔗 [Problem: NAKANJ - Minimum Knight Moves (SPOJ)](https://www.spoj.com/problems/NAKANJ/) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Minimum_Knight_moves__BFS.cpp) 

## 🔄 Cycle Detection Methods
- 🔗 [Unweighted, Using BFS](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_02/module_5/1_cycle_detect_using_bfs.cpp)
- 🔗 [Unweighted, Using DFS](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_02/module_5/2_cycle_detect_using_dfs.cpp)
- 🔗 [Unweighted, Directed Graph, Using DFS](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_02/module_5/4_cycle_detect_in_directed_graph.cpp)
- 🔗 [Weighted, Bellman Ford Negative Cycle Detection](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_02/module_7/2_detect_negative_cycle.cpp)
- 🔗 [Weighted, Floyd Warshall Negative Cycle Detection](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_02/module_7/8_is_cycle.cpp)


## 🚀 Dijkstra's Algorithm
- 🔗 [Problem: C. Dijkstra? (CF)](https://codeforces.com/contest/20/problem/C) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/C_Dijkstra__CF.cpp) **Shortest Path Printing**
- 🔗 [Problem: Shortest Routes I (CSES)](https://cses.fi/problemset/task/1671/) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Shortest_Routes_I__Dijkstra.cpp) **Don't forget to use INF = 1E18**

## 🔔 Bellman-Ford Algorithm
- 🔗 [Problem: Ford-Bellman (Basecamp)](https://basecamp.eolymp.com/en/problems/1453) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Ford_Bellman__Bellman_Ford.cpp) 
- 🔗 [Is Cycle?](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_02/module_7/2_detect_negative_cycle.cpp)

## 🛤️ Floyd-Warshall Algorithm
- 🔗 [Problem: Shortest Routes II (CSES)](https://cses.fi/problemset/task/1672/) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Shortest_Routes_II__Floyd_Warshall.cpp) 
- 🔗 [Is Cycle?](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_02/module_7/8_is_cycle.cpp)

## 🧩 Minimum Spanning Tree Algorithms
- 🔗 [DSU, Kruskals - all you need to know](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/tree/main/WEEK_03/module_11#readme)
- 🔗 [Problem: Building Roads (CSES)](https://cses.fi/problemset/task/1666/) | [DSU Union by Size](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Building_Roads__DSU_Union_By_Size.cpp) | [DSU Union by Rank](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Building_Roads__DSU_Union_By_Rank.cpp)
- 🔗 [MST](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_03/module_11/3_minimum_spanning_tree.cpp) will update
- 🔗 [Why MST](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/WEEK_03/module_11/5_why_mst.markdown) wil update and add oj statement

## 🔝 Topological Sorting Algorithms  (DAG)

<details>
<summary><strong>🟢 When to use which topsort</strong></summary>

DFS-based topo sort and BFS with a queue (Kahn’s algorithm) both detect cycles in DAGs while generating topological order, and BFS with a priority queue does the same but gives the **lexicographically smallest** order.

</details>

- 🔗 [Kahn’s algorithm (BFS) concept](https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/)
  
- 🔗 [Problem: Course Schedule (CSES)](https://cses.fi/problemset/task/1679/) | [Queue Version](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Course_Schedule___Topological_Sort_Queue_CSES.cpp) | [Priority Queue Version](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Course_Schedule___Topological_Sort_PriorityQueue_CSES.cpp) | [DFS Version](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Course_Schedule___Topological_Sort_DFS_Stack_CSES.cpp)
- 🔗 [Problem: TOPOSORT - Topological Sorting (SPOJ)](https://cses.fi/problemset/task/1671/) | [Code](https://github.com/sabbirahmedfahim/Introduction-to-Algorithms/blob/main/CP-Code/Topological_Sorting__SPOJ.cpp)

---

<br>

# Core Algorithms

## 🔄 Prefix Sum Techniques
- 🔗 [Prefix & Suffix](https://github.com/sabbirahmedfahim/Basic-Data-Structures/blob/main/WEEK_01/week01_day02/equilibrium_index.cpp)

## ⚠️ Pending Study Topics
- Dynamic Programming (Basic DP, 0-1 Knapsack and Variations)
- Unbounded Knapsack and Variations
- LCS DP and Variations (Longest Common Subsequence)
- Merge Sort