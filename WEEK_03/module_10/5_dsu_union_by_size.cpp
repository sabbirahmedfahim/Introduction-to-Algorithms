#include <bits/stdc++.h> // union by size && path compression 
// highly suggested the animated video ***
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1; // why group size? go check out dsu_union..size function to notice group_size++ 
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
void dsu_union(int node1, int node2) // Basic union operation (without size optimization)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    par[leaderA] = leaderB; // A er leader B
}
void dsu_union_by_size(int node1, int node2) // optimized version
{
    int leaderA = dsu_find(node1); /// Find the leader of node1
    int leaderB = dsu_find(node2); // Find the leader of node2

    // Attach the smaller group under the larger group ***
    if (group_size[leaderA] > group_size[leaderB])
    {
        // par[leaderA] = leaderB; // u should understand the logic why it is wrong
        par[leaderB] = leaderA; // The smaller group joins the larger group
        group_size[leaderA] += group_size[leaderB]; // Updating the size of the new group
    }
    else
    {
        par[leaderA] = leaderB; // The smaller group joins the larger group
        group_size[leaderB] += group_size[leaderA]; // Updating the size of the new group
    }
}
int main()
{
    // CAN YOU GUESS THE OUTPUT ??

    dsu_initialize(7); // Initialize DSU for 7 elements
    // dsu_union(1,2); // remove comment and run to understand
    // dsu_union(2,3); // remove comment and run to understand
    dsu_union_by_size(1, 2);
    dsu_union_by_size(2, 3);
    // 3-4 are not connected
    dsu_union_by_size(4, 5);
    dsu_union_by_size(5, 6);
    // finding the leaders of the two seperate groups
    cout << "leader of " << 1 << " is - " << dsu_find(1) << endl;
    cout << "leader of " << 5 << " is - " << dsu_find(5) << endl;
    // cout << "leader of " << 6 << " is - " << dsu_find(6) << endl;
    cout << endl << endl;

    // lets connect the two seperate groups
    dsu_union_by_size(1, 6); // Comment this out and uncomment the next line to understand the basics
    // dsu_union_by_size(6, 1);  

    // Now all nodes should have a common leader
    // Can you guess the output before checking it?
    cout << "leader of " << 1 << " is - " << dsu_find(1) << endl;
    cout << "leader of " << 2 << " is - " << dsu_find(2) << endl;
    cout << "leader of " << 6 << " is - " << dsu_find(6) << endl;

    return 0;
}