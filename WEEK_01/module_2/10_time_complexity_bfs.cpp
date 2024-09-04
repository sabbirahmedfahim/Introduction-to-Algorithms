#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005]; // problem, how it is normally O(V)? and, in worst case O(V*V)?
bool vis[1005]; // problem, how it is O(V)? 

void bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true; 
    bool flag = true;
    while (!q.empty()) // O(V+E) [time complexity]
    // V-> Vertex/Node, E-> Edge
    {
        pair<int, int> p = q.front();
        q.pop();    
        int par = p.first; // source
        int level = p.second; // level of parent
        if(par == des)  // condition
        {
            cout << level << endl;
            flag = false;
        }
        for(int child : v[par]) 
        {
            if(!vis[child]) 
            {
                q.push({child, level+1}); 
                vis[child] = true; 
            }
        }
    }
    if(flag) cout << -1 << endl;
}
int main()
{
    int n, e; cin >> n >> e;
    while (e--) // O(V) [space complexity]
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis)); 
    int des; // des-> destination
    cin >> des;
    bfs(src, des);   
    
    return 0;
}