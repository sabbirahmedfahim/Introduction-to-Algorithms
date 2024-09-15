#include <bits/stdc++.h>
using namespace std;

// my attempt (failed)
// class Solution {
// public:
//     bool vis[100000];
//     void dfs(vector<vector<int>>& edges, int source)
//     {
//         vis[source] = true;
//         for(int child : edges[source])
//         { 
//             if(!vis[child]) dfs(edges, child);
//         }
//     }
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
//     {
//         memset(vis, false, sizeof(vis));
//         dfs(edges, source);
//         return vis[destination];
//     }
// };

// instructors code
class Solution {
public:
    vector<int> v[200005];
    bool vis[200005];
    void dfs(int source)
    {
        vis[source] = true;
        for(int child : v[source])
        { 
            if(!vis[child]) dfs(child);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        memset(vis, false, sizeof(vis));
        for(int i = 0; i<edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(source);
        return vis[destination];
    }
};