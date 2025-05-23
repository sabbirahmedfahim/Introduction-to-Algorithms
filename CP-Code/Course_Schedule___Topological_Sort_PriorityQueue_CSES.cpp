#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 1E5 + 5;
vector<int> adj[N];
vector<int> indeg(N), topsort_res;
bool vis[N];
void topsort_bfs(int n)
{
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if(indeg[i] == 0)
        {
            vis[i] = true; q.push(i);
        }
    }
    
    while (!q.empty())
    {
        int par = q.top();
        q.pop();
        topsort_res.push_back(par);
        for(auto child : adj[par])
        {
            indeg[child]--;
            if(!vis[child] && indeg[child] == 0)
            {
                vis[child] = true; q.push(child);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n, e; cin >> n >> e;
    while (e--)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
 
        indeg[v]++;
    }
    memset(vis, false, sizeof(vis));
    topsort_bfs(n);
 
    if(topsort_res.size() != n)
    {
        cout << "IMPOSSIBLE" << nl;
    }
    else 
    {
        print(topsort_res);
    }
 
    return 0;
}
// https://cses.fi/problemset/task/1679/