#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool vis[N];
void dfs(int src) 
{
    vis[src] = true; 
    
    for (int child : v[src])
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
        v[a].push_back(b);
        v[b].push_back(a); // undirected graph
    }
    memset(vis, false, sizeof(vis)); 

    int src, des; cin >> src >> des;
    dfs(src);

    return 0;
}
/*
Input:
6 6
0 1
0 2
0 3 
1 4
3 5
3 2
1 5

*/