/*
Input:
5 8
0 1 10
0 2 7
0 3 4
1 4 2
2 4 5
2 1 1
3 4 5
3 2 1
0 4
Expected Output:
8
*/
/*
Please note that in the priority queue, we'll push {cost, source} pair to ensure proper
sorting by cost. 
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1E4;
vector<pair<int, int>> v[N]; // Node and weight (cost) pair
int dis[N]; /* dis == cost */
// int parent[N]; // track parent node
void dijkstra(int src) // O(logV(V+E)) -> O(VlogV + ElogV) -> O(VlogV + ElogE)
{
    /* PUSH {COST, SOURCE}, NOT {source, cost} *** */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap by default
    pq.push({0, src});
    dis[src] = 0;
    // parent[src] = -1; // track parent node
    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int cost = par.first; // or parentCost
        int node = par.second;  // or parentNode
        for (pair<int, int> child : v[node]) // range based for loop
        {
            int childNode = child.first; // don't confuse, we took input as {node, cost} format
            int childCost = child.second; // don't confuse, we took input as {node, cost} format
            if (cost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = cost + childCost;
                // parent[childNode] = node; // track parent node
                pq.push({dis[childNode], childNode}); // {COST, SOURCE}
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c; // c => cost
        cin >> a >> b >> c;
        v[a].push_back({b, c}); // as easy as you think. noting but an adj list
        v[b].push_back({a, c}); // undirected
    }
    
    memset(dis, 999999, sizeof(dis));
    // memset(parent, -1, sizeof(parent)); // parent tracking

    int src, des; cin >> src >> des;
    dijkstra(src);

    if(dis[des] == 999999) cout << "INF" << endl;
    else cout << dis[des] << endl;

    // des to 

    // for (int i = 0; i < n; i++) // from the source
    // {
    //     if(dis[i] == 999999) cout << " --> INF" << endl;
    //     else cout << i << "-> " << dis[i] << endl;
    // }

    return 0;
}