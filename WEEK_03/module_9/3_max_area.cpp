#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // vector<int> v[55];
    bool vis[55][55];
    int n, m;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int cnt;
    bool is_valid(int ci, int cj)
    {
        return ci >= 0 && ci < n && cj >= 0 && cj < m;
        // if(ci >= 0 && ci < n && cj >= 0 && cj < m) return true;
        // return false;
    }
    void dfs(int si, int sj, vector<vector<int>>& grid)
    {
        vis[si][sj] = true;
        cnt++;
        for(int i=0; i<4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            // if(is_valid(ci, cj) && !vis[ci][cj]) dfs(ci, cj); // mistake
            if(is_valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                dfs(ci, cj, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int mx = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    // int cnt = 0; // silly but non-noticeable mistake
                    cnt = 0; 
                    dfs(i, j, grid);
                    // cout << cnt << endl; // for cross checking
                    mx = max(mx, cnt);
                }
            }
        }
        return mx;
    }
};