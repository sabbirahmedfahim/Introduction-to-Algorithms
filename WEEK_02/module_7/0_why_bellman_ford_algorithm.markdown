## Shortest Path Algorithms Recap

---
### BSF Algorithm
**BFS**: Complexity O(V + E). BFS only works for unweighted graphs.
   
---
### Dijkstra Algorithm
**Dijkstra**: It works on weighted graphs, but it doesn't handle negative weights properly. Specifically, **Dijkstra's algorithm fails in the presence of a negative weight cycle**. In such cases, it can enter an infinite loop because it keeps trying to reduce the total cost. 

   ![alt text](image.png)
   ![alt text](image-1.png)
   ![alt text](image-2.png)

**The images show an infinite loop!** This occurs due to a negative weight cycle, which Dijkstra cannot handle. To address this, we use the Bellman-Ford algorithm. **It’s important to understand two terms: negative weight and negative weight cycle.** Dijkstra can handle negative weights as long as they don’t form a cycle. **If it's confirmed that no negative weight cycles exist in the graph, Dijkstra's algorithm can be used safely.**


--- 
### Bellman Ford Algorithm
**Bellman Ford Algorithm**: 
   Unlike Dijkstra's algorithm, Bellman-Ford works for graphs with negative weights and is **capable of detecting and handling negative weight cycles.**