#include <bits/stdc++.h>
using namespace std;

// it's better to re-watch module before revise
class Solution {
public:
    int n, m;
    bool vis[505][505];
    bool valid(int ci, int cj) {
        return (ci >= 0 && ci < n && cj >= 0 && cj < m);
    }
    bool flag;
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void dfs(int si, int sj, vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        vis[si][sj] = true;
        if(grid1[si][sj] == 0) // here is the catch
        {
            flag = false;
            // return; // why using return is wrong here?
        }
        for(int i=0; i<4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && grid2[ci][cj] == 1)
            {
                dfs(ci, cj, grid1, grid2);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int ans = 0;
        memset(vis, false, sizeof(vis));
        n = grid1.size();
        m = grid1[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid2[i][j]) 
                {
                    flag = true; // before calling, let flag is true
                    dfs(i, j, grid1, grid2);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};