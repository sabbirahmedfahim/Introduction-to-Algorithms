/*
class Solution {
public:
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool vis[1005][1005];
    bool ok;
    bool isValid(int ci, int cj, int row, int col)
    {
        return(ci >= 0 && ci < row && cj >= 0 && cj < col);
    }
    void dfs(int si, int sj, vector<vector<int>>& grid, int row, int col)
    {
        vis[si][sj] = true;
        if(si == 0 || sj == 0 || si == row-1 || sj == col-1) ok = false;
        for(int i=0; i<4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(isValid(ci, cj, row, col) && !vis[ci][cj] && grid[ci][cj] == 0)
            {
                dfs(ci, cj, grid, row, col);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        memset(vis, false, sizeof(vis));
        int row = grid.size(), col = grid[0].size();

        int cnt = 0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 0 && !vis[i][j])
                {
                    ok = true;
                    dfs(i, j, grid, row, col);
                    if(ok) cnt++;
                }
            }
        }

        return cnt;
    }
};
*/
// https://leetcode.com/problems/number-of-closed-islands/description/