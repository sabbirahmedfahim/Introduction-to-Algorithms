#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5; // N = 100005 // constant integer
vector<int> v[N];
bool vis[N];
void dfs(int src) // when ur job is to randomly traverse the graph :p
{
    cout << src << " ";
    vis[src] = true; // tracking
    for (int child : v[src])
    {
        if(!vis[child]) dfs(child); // recursive solution. it's amazing
    }
}
int main()
{
    int n, e; cin>> n >> e;
    while (e--)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis)); // initialized vis with false
    dfs(0);


    return 0;
}