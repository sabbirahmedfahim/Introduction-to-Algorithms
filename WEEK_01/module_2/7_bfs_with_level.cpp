#include <bits/stdc++.h>
using namespace std;
/*Note: at the first test case: 7, 8, 9 they are connected with each other.
Since we're looking for nodes who are connected with SOURCE, they remains
disconnected with our source, we assumed they are not connected.
On the other hand, in the test case 2: we assumed 8 as SOURCE, so every nodes 
except 7, 8, 9 are disconnected. That's how we independently search levels based 
on any nodes as source*/
vector<int> v[1005]; 
bool vis[1005]; 
int level[1005]; // declared level for tracking levels
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true; 
    level[src] = 0; // initialized src level with 0
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl; // priting in level order !
        for(int child : v[par]) 
        {
            if(!vis[child]) 
            {
                q.push(child); 
                vis[child] = true; 
                level[child] = level[par] + 1; // every child has parent, parent level pre-declared
            }
        }
    }
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
    memset(level, -1, sizeof(level)); // initialized level values with -1
    // some nodes can be disconnected, to avoid garbage values, initialized all level with -1
    bfs(src);
    cout << endl;
    for (int i = 0; i < n; i++) // printing nodes(not level wise), mentioning their levels
    {
        cout << "level of " << i << " is " << level[i] << endl;
    }
    
    return 0;
}