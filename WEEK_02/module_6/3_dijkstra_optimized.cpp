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
#include <bits/stdc++.h>
using namespace std;
const int N = 1E4;
vector<pair<int, int>> v[N]; // Node and weight (cost) pair
int dis[N]; /* dis == cost */

void dijkstra(int src) // O(logV(V+E)) -> O(VlogV + ElogV) -> O(VlogV + ElogE)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap by default
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;  // or nodeVal or parentNode
        int cost = parent.second; // or parentCost
        for (pair<int, int> child : v[node]) // range based for loop
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]}); // dis[childNode] bola r (cost+childCost) bola ekh kotha
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

    int src, des; cin >> src >> des;
    dijkstra(src);

    if(dis[des] == 999999) cout << "INF" << endl;
    else cout << dis[des] << endl;

    // for (int i = 0; i < n; i++) // from the source
    // {
    //     if(dis[i] == 999999) cout << " --> INF" << endl;
    //     else cout << i << "-> " << dis[i] << endl;
    // }

    return 0;
}