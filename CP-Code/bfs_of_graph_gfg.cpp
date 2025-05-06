/*
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) 
    {
        // Code here
        int N = 1E4 + 5;
        bool vis[N];
        int dis[N];
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        
        vector<int> res;
        res.push_back(0);
        
        dis[0] = 0;
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        while(!q.empty())
        {
            int par = q.front();
            q.pop();
            for(auto e : adj[par])
            {
                if(!vis[e])
                {
                    vis[e] = true;
                    res.push_back(e);
                    q.push(e);
                }
            }
        }
        
        return res;
    }
};
*/