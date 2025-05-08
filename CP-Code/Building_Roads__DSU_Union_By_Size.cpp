#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N]; 
void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if(parent[node] == -1) return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader; 
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if(leaderA == leaderB) return;

    if(group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    } 
}
int main()
{
    int n, e; cin >> n >> e;
    dsu_initialize(n); 
    while (e--)
    {
        int node1, node2; cin >> node1 >> node2;
        dsu_union_by_size(node1, node2); 
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
