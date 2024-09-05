A 2D grid, represented as a 2D matrix, can be traversed using BFS (Breadth-First Search) or DFS (Depth-First Search), similar to how we traverse graphs. Each cell in the grid can be considered a node, and the edges connect neighboring cells (usually the cells to the left, right, top, and bottom).

| Direction     | i    | j    | Changes |
|---------------|------|------|---------|
| src -> right  | i    | j+1  |  0, 1   |
| src -> left   | i    | j-1  |  0, -1  |
| src -> top    | i-1  | j    | -1, 0   |
| src -> bottom | i+1  | j    |  1, 0   |
-----------------------------------------

**Column Change**: right, left  
**Row Change**: top, bottom


right, left => column change
top, bottom => row    change