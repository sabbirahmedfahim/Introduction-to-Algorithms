#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        level[i] = 0; 
    }
}
int dsu_find(int node) 
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader; 
    return leader;
}
void dsu_union_by_level(int node1, int node2) // (height of the tree)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2); 

    if(leaderA == leaderB) return; 

    // Compare the levels (heights) of the two leaders
    if(level[leaderA] > level[leaderB]) 
    {
        par[leaderB] = leaderA; 
    }
    else if (level[leaderB] > level[leaderA]) 
    {
        par[leaderA] = leaderB;
    }
    else 
    {
        par[leaderA] = leaderB; 
        level[leaderB]++;
    }
}

int main()
{
    int n, e; cin >> n >> e;
    dsu_initialize(n); 
    while (e--)
    {
        int node1, node2; cin >> node1 >> node2;
        dsu_union_by_level(node1, node2); 
    }
    set<int> leaders;
    for (int i = 1; i <= n; i++)
    {
        leaders.insert(dsu_find(i));
    }
    
    vector<int> res;
    for(auto e : leaders) res.push_back(e);

    cout << res.size() - 1 << nl;
    for (int i = 0; i < res.size()-1; i++)
    {
        cout << res[i] << " " << res[i + 1] << nl;
    }

    return 0;
}
// https://cses.fi/problemset/task/1666/