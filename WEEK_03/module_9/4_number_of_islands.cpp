// my code
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vis[305][305];
    int n, m;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool is_valid(int ci, int cj)
    {
        return ci >= 0 && ci < n && cj >= 0 && cj < m;
    }
    void dfs(int si, int sj, vector<vector<char>>& grid)
    {
        vis[si][sj] = true;
        for(int i=0; i<4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(is_valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '1')
            {
                dfs(ci, cj, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++; 
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};