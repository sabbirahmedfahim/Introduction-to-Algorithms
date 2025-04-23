/*
Input:
5 8
0 1 10
0 2 7
0 3 4
1 4 3
2 4 5
2 1 1
3 4 5
3 2 1
0 4
Output:
9
*/
/*
Please note that in the priority queue, we'll push {cost, source} pair to ensure proper
sorting by cost. 
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1E4;
vector<pair<int, int>> v[N];
int dist[N]; /* dist == cost */
int parent[N]; // track parent node
void dijkstra(int source) // O(logV(V+E)) -> O(VlogV + ElogV) -> O(VlogV + ElogE)
{
    /* PUSH {COST, SOURCE}, NOT {source, cost} *** */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap by default
    pq.push({0, source});
    dist[source] = 0;
    parent[source] = -1; // track parent node
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
            if (cost + childCost < dist[childNode])
            {
                // path relax
                dist[childNode] = cost + childCost;
                parent[childNode] = node; // track parent node
                pq.push({dist[childNode], childNode}); // {COST, SOURCE}
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
        v[a].push_back({b, c});
        v[b].push_back({a, c}); // undirected
    }
    
    memset(dist, 999999, sizeof(dist));
    memset(parent, -1, sizeof(parent)); // parent tracking

    int source, destination; cin >> source >> destination;
    dijkstra(source);

    int tmp = destination;
    vector<int> path;
    while (tmp != -1) 
    {
        path.push_back(tmp);
        tmp = parent[tmp];
    }
    
    if(dist[destination] == 999999)
    {
        cout << "Disconnected" << endl;
    }
    reverse(path.begin(), path.end());

    // shortest path
    for(auto e : path) cout << e << " "; cout << endl;

    return 0;
}