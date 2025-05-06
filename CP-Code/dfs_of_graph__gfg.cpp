/*
    class Solution {
      public:
      
        vector<int> res;
        bool vis[10004];
        
        void DFS(int src, vector<vector<int>>& adj)
        {
            res.push_back(src);
            vis[src] = true;
            for(auto e : adj[src])
            {
                if(!vis[e]) DFS(e, adj);
            }
        }
        
        vector<int> dfs(vector<vector<int>>& adj) 
        {
            // Code here
            memset(vis, false, sizeof(vis));
            DFS(0, adj);
            
            return res;
        }
    };
*/