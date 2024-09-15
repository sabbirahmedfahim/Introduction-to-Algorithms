#include <bits/stdc++.h>
using namespace std;
const int N = 100;
// vector<int> v[N];
vector<pair<int, int>> v[N]; // node, weight(cost) pair
int dis[N];                  // dis-> distance
void dijkstra(int src)       // O(V*E) -> bad time complexity in the naive version
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty()) 
    {
        pair<int, int> parent = q.front();
        q.pop();
        int node = parent.first;  // AKA nodeVal or parentNode
        int cost = parent.second; // AKA parentCost
        // for(int i=0; i < v[node].size(); i++) // accurate code
        // {
        //     pair<int, int> child = v[node][i];
        // }
        for (pair<int, int> child : v[node]) // range based for loop
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]}); // dis[childNode] bola r (cost+childCost) bola ekh kotha
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
        v[b].push_back({a, c});
    }
    // memset(dis, INT_MAX, sizeof(dis)); // INT_MAX sometimes not work in memset
    for (int i = 0; i < n; i++) // using for loop as memset not working properly
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << "-> " << dis[i] << endl;
    }

    return 0;
}