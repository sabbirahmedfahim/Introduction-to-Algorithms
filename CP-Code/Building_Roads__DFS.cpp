#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjList[N];
bool vis[N];    
void dfs(int src)
{
    vis[src] = true;
    
    for (int child : adjList[src])
    {
        if(!vis[child]) 
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e; cin>> n >> e;
    while (e--)
    {
        int a, b; cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a); 
    }
    memset(vis, false, sizeof(vis)); 

    vector<int> roadsRequired;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            roadsRequired.push_back(i);
            dfs(i);
        }
    }
    
    cout << roadsRequired.size() - 1 << endl;
    if(roadsRequired.size() > 1)        
    {
        for (int i = 0; i < roadsRequired.size()-1; i++)
        {
            cout << roadsRequired[i] << " " << roadsRequired[i + 1] << endl;
        }
    }

    return 0;
}