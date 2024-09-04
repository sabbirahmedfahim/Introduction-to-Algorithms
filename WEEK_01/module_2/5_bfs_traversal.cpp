#include <bits/stdc++.h>
using namespace std;
// vector<int> v(1005); // 1D
vector<int> v[1005]; // 2D
bool vis[1005]; // vis -> visited -> track visited nodes
void bfs(int src)
{
    queue<int> q;
    q.push(src); // pushed source
    vis[src] = true; // visited source
    while (!q.empty())
    {
        int par = q.front(); // par -> parent 
        q.pop();
        cout << par << endl; // priting in level order !
        for(int child : v[par]) // shortcut
        {
            // if(vis[child] == false) // accurate
            if(!vis[child]) 
            {
                q.push(child); 
                vis[child] = true; // tracking nodes
            }
        }
    }
}
int main()
{
    int n, e; cin >> n >> e;
    while (e--)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src; // src -> source
    cin >> src;
    memset(vis, false, sizeof(vis)); // initialized visited nodes with false
    bfs(src);

    return 0;
}