#include <bits/stdc++.h> // goto 9_bfs_level_pair.cpp for clean code
using namespace std;

vector<int> v[1005]; 
bool vis[1005]; 
// int level[1005]; // gonna initialize level with pair

// void bfs(int src)
void bfs(int src, int des)
{
    // queue<int> q; // gonna make a pair
    queue<pair<int, int>> q; // int, int pair AKA source, level pair created! 
    // q.push(src);
    q.push({src, 0});
    vis[src] = true; 
    // level[src] = 0; // no need
    bool flag = true; // added flag for checking
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();    
        int par = p.first; // source
        int level = p.second; // level of parent
        // cout << par << endl; // priting in level order !
        if(par == des)  // condition
        {
            cout << level << endl;
            flag = false;
        }
        for(int child : v[par]) 
        {
            if(!vis[child]) 
            {
                // q.push({par, child}); // wrong
                q.push({child, level+1}); // push children, level of children
                vis[child] = true; 
                // level[child] = level[par] + 1; // no need
            }
        }
    }
    if(flag) cout << -1 << endl; // added
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
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis)); 
    // memset(level, -1, sizeof(level)); // it should not work now
    // some nodes can be disconnected, to avoid garbage values, initialized all level with -1
    int des; // des-> destination
    cin >> des;
    bfs(src, des);   
    
    
    return 0;
}