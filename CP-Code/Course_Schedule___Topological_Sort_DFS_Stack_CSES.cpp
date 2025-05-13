#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(), c.end()
#define print(c) for (auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 1E5 + 5;
vector<int> adj[N];
int vis[N];
stack<int> topsort_res;
/* 0 --> unvisited, 1 --> visiting, 2 --> visited */
bool dfs(int node)
{
    if (vis[node] == 1) return false;
    if (vis[node] == 2) return true;
 
    vis[node] = 1;
    for (int child : adj[node])
    {
        if (!dfs(child)) return false;
    }
    vis[node] = 2;
    topsort_res.push(node);
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
 
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (!dfs(i))
            {
                cout << "IMPOSSIBLE" << nl;
                return 0;
            }
        }
    }
 
    while (!topsort_res.empty())
    {
        cout << topsort_res.top() << " ";
        topsort_res.pop();
    }
    cout << nl;
 
    return 0;
}
// https://cses.fi/problemset/task/1679/
/*
Input: (understanding cycle detection using recursion)
4 4
1 2
2 3
3 4
4 1
 
Expected Output:
IMPOSSIBLE
 
*/
