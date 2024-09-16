#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }
    // you should imagine/draw the array and parent-node relation
    par[1] = 2;
    par[2] = 3;
    par[5] = 6;
    par[6] = 7;
}
int dsu_find(int node) // highly suggested animated video
{
    if (par[node] == -1) return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
} 
void dsu_union(int node1, int node2) 
{
    int leaderA = dsu_find(node1); // it will return the leader of node1
    int leaderB = dsu_find(node2); // it will return the leader of node2
    par[leaderA] = leaderB; // sacrificing the leaderA, now single leader of the union is mr leaderB
}
int main()
{
    dsu_initialize(8); // size
    cout << "leader/parent of " << 1 << " is - " << dsu_find(1) << endl; 
    dsu_union(1, 5); // changed the leader hehehe
    cout << "leader/parent of " << 1 << " is - " << dsu_find(1) << endl; 
    
    return 0;
}