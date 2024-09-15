#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
bool pathVisit[N];
vector<int> adj[N];
bool flag = false;
void dfs(int parent) // source
{
    vis[parent] = true;
    pathVisit[parent] = true; // visited path and marked it as true
    // cout << parent << endl;
    for (int child : adj[parent])
    {
        if(pathVisit[child]) 
        {
            flag = true;
            break;
        }
        if (!vis[child])
        {
            dfs(child);
        }
    }
    // kaj shese path visit false kore dibo
    pathVisit[parent] = false; // think in a recursive way  
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
    }
    memset(vis, false, sizeof(vis)); // initially visit false
    memset(pathVisit, false, sizeof(pathVisit)); // initially path visit false
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]) dfs(i);
    }
    if(flag) cout << "Cycle detected";
    else cout << "Cycle not detected";
 
    return 0;
}