#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int parentArr[N]; // tracking parent to detect two nodes(parent-children vise-verca) cycle (0)----(1)
bool flag = false;
void dfs(int parent) // source
{
    vis[parent] = true;
    // cout << parent << endl;
    for(int child : adj[parent])
    {
        if(vis[child] && parentArr[parent] != child)
        {
            flag = true; 
            break;
        }
        if(!vis[child])
        {
            parentArr[child] = parent;
            dfs(child);
            // parentArr[child] = parent; // recursive function, so write this before calling the function
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
        if (!vis[i]) dfs(i);
    } 
    // for (int i = 0; i < n; i++) // u should make a graph using input and UNDERSTAND the for loop
    // {
    //     cout << parentArr[i] << " "; // printing parents
    // }
    
    if(flag) cout << "Cycle detected!"; 
    else cout << "Cycle not found";

    return 0;
}