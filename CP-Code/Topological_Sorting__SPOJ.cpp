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
    // queue<int> q; // got WA for using queue
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if(indeg[i] == 0)
        {
            vis[i] = true; pq.push(i);
        }
    }
 
    while (!pq.empty())
    {
        // int par = q.front();
        int par = pq.top();
        pq.pop();
        topsort_res.push_back(par);
        for(auto child : adj[par])
        {
            indeg[child]--;
            if(indeg[child] == 0 && !vis[child])
            {
                vis[child] = true;
                pq.push(child);
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
        cout << "Sandro fails." << nl; return 0;
    }
    else
    {
        print(topsort_res);
    }
 
    return 0;
} 