#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pi pair<int, int>
#define nl '\n'
using namespace std;
int n, e;
const ll INF = 1e18; // inf -> infinite

vector<pi> adj[100005]; // adjacency list {weight, node} // array of vectors
ll dis[100005];
ll par[100005];
void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[src] = 0; // Set the source node distance to 0 // changed infinity to zero distance

    /*RULE: If dis[u] + edge < dis[v], then update the shortest path (relaxation)*/ 
    // Priority queue stores pairs of {distance, node}, 
    priority_queue<pi, vector<pi>, greater<pi>> pq; // CHOTO THEKE BORO [ironically, greater dile choto theke boro, normally boro theke choto sort kore]
    /* Priority queue is set to work from smallest to largest values (weights).
    Understanding this concept is key to Dijkstra's algorithm. */
    pq.push({dis[src], src});  

    while (!pq.empty())
    {
        pi parent = pq.top(); // Get the node with the smallest distance
        pq.pop();
        int parentNode = parent.second;
        int parentCost = parent.first;

        // Explore all adjacent nodes (children)
        for (pi child : adj[parentNode])
        {
            int childCost = child.first;
            int childNode = child.second;
            if (dis[parentNode] + childCost < dis[childNode]) // relaxation step
            {
                dis[childNode] = dis[parentNode] + childCost; // Update distance (relaxation)
                pq.push({dis[childNode], childNode});  // Push updated distance and node TO EXPLORE SHORTER PATHS FROM THIS NODE
                par[childNode] = parentNode; // Record the parent to path tracing
            }
        }
    }
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v}); // Push {weight, node} // i can also push the node first, doesn't matter, just follow the rules
        adj[v].push_back({w, u});
    }
    memset(par, -1, sizeof(par));
    int src = 1;
    dijkstra(src);
    // for (int i = 1; i <= n; i++) // print distance (for cross checking)
    // {
    //     cout << dis[i] << " ";
    // }
    vector<int> v;
    int current = n;
    while (true)
    {
        v.push_back(current);  // If node n is not visited, this will cause a segmentation fault. So, check visited nodes first. [i fixed this, check 2_dijkstra.cpp]
        if(current == src) break;
        current = par[current]; // n er parent n-1, n-1 er parent n-2, eivabe // Trace the path back from n to 1
    }

    reverse(v.begin(), v.end()); 
    for(int data : v) cout << data << " ";

    return 0;
}