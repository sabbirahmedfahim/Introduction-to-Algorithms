# 2D Grid Traversal using BFS and DFS


## Standard 4-Directional Moves

| Direction | Coordinate Change | Change (i, j) |
|-----------|-------------------|---------------|
| Right     | Column +1         | (0, +1)       |
| Left      | Column -1         | (0, -1)       |
| Top       | Row -1            | (-1, 0)       |
| Bottom    | Row +1            | (+1, 0)       |

- **Column changes**: Right (+1), Left (-1)
- **Row changes**: Top (-1), Bottom (+1)

---

## Knight Moves (8-Directional)

![Knight Moves Diagram](image-2.png)

Possible L-shaped moves in chess:

```cpp
vector<pair<int, int>> knightMoves = {
    {2, 1}, {2, -1},   // Right movements
    {-2, 1}, {-2, -1},  // Left movements
    {1, 2}, {1, -2},    // Down movements
    {-1, 2}, {-1, -2}   // Up movements
};