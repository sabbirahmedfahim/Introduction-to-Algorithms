#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int parentArr[N]; // tracking parent to detect two nodes(parent-children vise-verca) cycle (0)----(1)
bool flag = false;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        // cout << parent << endl;
        q.pop();
        for (int child : adj[parent])
        {
            // if child != parent & visited array : Cycle found! For the reason, we track parent
            if(vis[child] && parentArr[parent] != child) // concentrate here
            {
                flag = true; break;
            }
            if (!vis[child])
            {
                vis[child] = true;
                parentArr[child] = parent; // *** in the parentArr, storing in child-th index the value of parent
                q.push(child);
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parentArr, -1, sizeof(parentArr));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i]) bfs(i);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << parentArr[i] << " ";
    // }
    
    if(flag) cout << "Cycle detected!";
    else cout << "Cycle not found";

    return 0;
}