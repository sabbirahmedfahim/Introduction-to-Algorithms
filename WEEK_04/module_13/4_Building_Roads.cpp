/*
tips: if they mention 'from a to b' -> directed graph
if the statement refers 'between' -> undirected graph
*/
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
    if(group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB]+=group_size[leaderA];
    } 
}
int main()
{ // don't worries if the sample test cases do not match. there're multiple answers
    int n, e; cin >> n >> e;
    dsu_initialize(n); 
    while (e--)
    {
        int node1, node2; cin >> node1 >> node2;
        if(dsu_find(node1) != dsu_find(node2)) dsu_union_by_size(node1, node2); // condition used to prevent cycle
    }
    vector<int> leaderRakhbo;
    for (int i = 1; i <= n; i++)
    {
        leaderRakhbo.push_back(dsu_find(i));
    }
    // finding unique value method: 
    sort(leaderRakhbo.begin(), leaderRakhbo.end()); // step-1: sort
    leaderRakhbo.erase(unique(leaderRakhbo.begin(), leaderRakhbo.end()), leaderRakhbo.end()); // step-2: erase duplicates after sorting
    cout << leaderRakhbo.size()-1 << nl; // you MUST understand the logic behind this
    for (int i = 0; i < leaderRakhbo.size()-1; i++) // if MUST understand the logic behind size-1
    {
        cout << leaderRakhbo[i] << " " << leaderRakhbo[i+1] << nl;
    }
    

    return 0;
}