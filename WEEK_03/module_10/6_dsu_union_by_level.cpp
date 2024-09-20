#include <bits/stdc++.h> // level by && size by both are optimized. easy any of them freely
// highly suggested the animated video ***
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        // group_size[i] = 1; // used for dsu_union_by_level
        level[i] = 0; // initializing levels with 0
    }
}
int dsu_find(int node) // Uses path compression for optimization
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader; // path compression
    return leader;
}
void dsu_union(int node1, int node2) // Simple union without optimizations (not recommended)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    par[leaderA] = leaderB;
}
void dsu_union_by_level(int node1, int node2) // optimized version ((height of the tree))
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2); 

    // Compare the levels (heights) of the two leaders
    if(level[leaderA] > level[leaderB]) // level remains same
    {
        par[leaderB] = leaderA; // Attach the shorter tree under the taller tree
    }
    else if (level[leaderB] > level[leaderA]) // level remains same
    {
        par[leaderA] = leaderB; // Attach the shorter tree under the taller tree
    }
    else 
    {
        // If both leaders have the same level, attach any one to the other
        par[leaderA] = leaderB; 
        level[leaderB]++; // Increase the level of the new leader's tree by 1
    }
}

int main()
{
    dsu_initialize(7); // Initialize DSU for 7 elements
    dsu_union_by_level(1, 2);
    dsu_union_by_level(2, 3);
    // 3-4 are not connected
    dsu_union_by_level(4, 5);
    dsu_union_by_level(5, 6);
    // finding the leaders of the two seperate groups
    cout << "leader of " << 1 << " is - " << dsu_find(1) << endl;
    cout << "leader of " << 2 << " is - " << dsu_find(2) << endl;
    cout << "leader of " << 6 << " is - " << dsu_find(6) << endl << endl << endl;

    // lets connect the two seperate groups
    dsu_union_by_level(1, 6); // Comment this out and uncomment the next line to understand the basics
    // dsu_union_by_size(6, 1);  

    // Now all nodes should have a common leader
    // Can you guess the output before checking it?
    cout << "leader of " << 1 << " is - " << dsu_find(1) << endl;
    cout << "leader of " << 2 << " is - " << dsu_find(2) << endl;
    cout << "leader of " << 6 << " is - " << dsu_find(6) << endl;

    return 0;
}