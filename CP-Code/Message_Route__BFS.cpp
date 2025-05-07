#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 5;
vector<int> adjList[N];
bool vis[N];
int level[N]; /* level == distance == cost */  
int parent[N]; // parent, par variable are different
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adjList[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1; /* level == distance == cost */  
                parent[child] = par; // parent, par variable are different
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int src = 1, des = n;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfs(src);

    if(level[des] == -1)
    {
        cout << "IMPOSSIBLE" << endl; return 0;
    }

    int temp = des;
    vector<int> path;
    while (temp != -1)
    {
        path.push_back(temp);
        temp = parent[temp];
    }

    cout << level[des] + 1 << endl;
    reverse(path.begin(), path.end());
    for (int val : path)
    {
        cout << val << " ";
    }
    return 0;
}
// https://cses.fi/problemset/task/1667