#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> v[N]; // node, weight(cost) pair
int dis[N]; // dis-> distance
class cmp // creating a compare class for sorting
{
public: 
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second; // true or false, return korbeiiii 
    }
};
void dijkstra(int src) // O(logV(V+E)) -> O(VlogV + ElogV) -> O(VlogV + ElogE)
{
    // queue<pair<int, int>> q; // used in the naive version
    // priority_queue<pair<int, int>, vector < pair < int, int >>> pq; // represents priority queue (version 1.pq)
    priority_queue<pair<int, int>, vector < pair < int, int >>, cmp > pq; // represents priority queue (compare class added)
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        // pair<int, int> parent = pq.front(); // not front
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;  // AKA nodeVal or parentNode
        int cost = parent.second; // AKA parentCost
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
        v[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++) // using for loop as memset not working properly
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);

    /*
    // THIS PART IS NOT UNDERSTANDING HOW PRIORITY QUEUE WORKS
    priority_queue<pair<int, int>, vector < pair < int, int >>> pq;
    priority_queue<pair<int, int>, vector < pair < int, int >>, cmp> pq; // added cmp class
    pq.push({1, 10});
    pq.push({3, 7});
    pq.push({2, 15});
    pq.push({4, 5});
    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    */

    for (int i = 0; i < n; i++)
    {
        cout << i << "-> " << dis[i] << endl;
    }

    return 0;
}