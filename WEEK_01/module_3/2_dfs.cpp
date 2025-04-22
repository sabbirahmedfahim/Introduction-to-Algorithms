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
Output: 
Path from 1 to 5: 1 0 2 3 5 
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool vis[N];
int parent[N]; // TRACK PARENTS

void dfs(int src) // when ur job is to randomly traverse the graph :p
{
    // cout << src << " ";
    vis[src] = true; // mark visited
    
    for (int child : v[src])
    {
        if(!vis[child]) 
        {
            parent[child] = src; // TRACK PARENTS
            dfs(child); // recursive solution. it's amazing
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
    memset(vis, false, sizeof(vis)); // initialized vis with false
    memset(parent, -1, sizeof(parent)); // TRACK PARENTS

    int src, des; cin >> src >> des;
    dfs(src);

    /* TRACK PARENTS  __start */
    if (vis[des]) 
    {
        // **Note: This may not be the shortest path (use BFS for the shortest path)**
        cout << "Path from " << src << " to " << des << ": ";
        
        vector<int> path;

        int tmp = des;
        while (tmp != -1)
        {
            path.push_back(tmp);
            tmp = parent[tmp];
        }
        reverse(path.begin(), path.end());
        for(auto e : path) cout << e << " "; cout << endl;
    } 
    else cout << "No path from " << src << " to " << des << endl;
    /* TRACK PARENTS __end */ 

    return 0;
}
