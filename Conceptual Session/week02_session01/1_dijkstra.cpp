// Problem Link: https://codeforces.com/problemset/problem/20/C

// BASIC [check the bottom to get the final code]
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pi pair<int, int>
#define nl '\n'
using namespace std;
int n, e;
const ll INF = 1e18; // inf -> infinite

vector<pi> adj[100005];
ll dis[100005];
ll par[100005];
void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[src] = 0; // Set the source node distance to 0 // changed infinity to zero distance

    /*Rule: If dis[u] + edge < dis[v], then update the shortest path (relaxation)*/ 
    // Priority queue stores pairs of {distance, node}, 
    priority_queue<pi, vector<pi>, greater<pi>> pq; // // Min-heap storing {distance, node} pairs // sorted by the smallest distance (min-heap)
    pq.push({dis[src], src});  // INITIAL PUSH of the source node into the priority queue

    while (!pq.empty())
    {
        pi parent = pq.top();
        pq.pop();
        int parentNode = parent.second; // because node value at the second portion {weight, value}
        int parentCost = parent.first;
        for (pi child : adj[parentNode])
        {
            int childCost = child.first;
            int childNode = child.second;
            if (dis[parentNode] + childCost < dis[childNode]) // relaxation step
            {
                dis[childNode] = dis[parentNode] + childCost; // Relax and update the distance
                pq.push({dis[childNode], childNode});  // Push the updated distance and node TO EXPLORE SHORTER PATHS FROM THIS NODE
                par[childNode] = parentNode; // Record the parent to trace the shortest path
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
        adj[u].push_back({w, v}); // Push weight first, then the node // i can also push the node first, doesn't matter, just follow the rules
        adj[v].push_back({w, u}); // Push weight first, then the node
    }
    memset(par, -1, sizeof(par));
    int src = 1;
    dijkstra(src);
    // for (int i = 1; i <= n; i++) // print distance
    // {
    //     cout << dis[i] << " ";
    // }
    vector<int> v;
    int current = n;
    while (true)
    {
        v.push_back(current);  // If node n is not visited, this will cause a segmentation fault. So, check visited nodes first. [i fixed this at the final code, check the bottom]
        if(current == src) break;
        current = par[current]; // n er parent n-1, n-1 er parent n-2, eivabe // Trace the path back from n to 1
    }

    reverse(v.begin(), v.end());
    for(int data : v) cout << data << " ";

    return 0;
}

// Solution
// #include <bits/stdc++.h>
// #define ll long long int
// #define ull unsigned long long int
// #define pi pair<int, int>
// #define nl '\n'
// using namespace std;
// int n, e;
// const ll INF = 1e18; // inf -> infinite

// vector<pi> adj[100005];
// ll dis[100005];
// ll par[100005];
// bool vis[100005];
// void dijkstra(int src)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = INF;
//     }
//     dis[src] = 0;

//     priority_queue<pi, vector<pi>, greater<pi>> pq;
//     pq.push({dis[src], src});
//     vis[src] = true;

//     while (!pq.empty())
//     {
//         pi parent = pq.top();
//         pq.pop();
//         int parentNode = parent.second;
//         int parentCost = parent.first;
//         vis[parentNode] = true;

//         for (pi child : adj[parentNode])
//         {
//             int childCost = child.first;
//             int childNode = child.second;
//             if (dis[parentNode] + childCost < dis[childNode])
//             {
//                 dis[childNode] = dis[parentNode] + childCost;
//                 pq.push({dis[childNode], childNode});
//                 par[childNode] = parentNode;
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> n >> e;
//     while (e--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({w, v});
//         adj[v].push_back({w, u});
//     }
//     memset(par, -1, sizeof(par));
//     memset(vis, false, sizeof(vis));
//     int src = 1;
//     dijkstra(src);
//     if (!vis[n])
//     {
//         cout << -1 << nl;
//     }
//     else
//     {
//         vector<int> v;
//         int current = n;
//         while (true)
//         {
//             v.push_back(current);
//             if (current == src) break;
//             current = par[current];
//         }

//         reverse(v.begin(), v.end());

//         for (int data : v) cout << data << " ";
//     }

//     return 0;
// }