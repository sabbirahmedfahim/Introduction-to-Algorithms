#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*keep in mind, there's no valid answer of if a graph has negative cycle*/ 
class Edge
{
public:
    int u, v, c; // u -> source, v -> destination, c-> youKnowWHat
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1e5 + 5;
ll inf = 1E18;
ll dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edgeList; // <Edge> contains three values (u, v, c)
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c)); // i hafta understand this
        // edgeList.push_back(Edge(v, u, c)); // for undirected graph 
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = inf;
    }
    // let's say source is 0, we initialized the source with INT_MAX, doesn't make sense.
    dis[0] = 0; // fixed the source value

    // i er kaj nai -> just (n-1) bar loop cholbe according to our algorithm
    for (int i = 1; i <= n - 1; i++) // O(V*E)
    {
        for (Edge ed : edgeList) // O(E)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool isCycle = false;
    for (Edge ed : edgeList) // It's exactly N times we're executing edgeList to detect cycle
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            isCycle = true;
            break;
            dis[v] = dis[u] + c;
        }
    }
    if(isCycle) cout << "Cycle found. No valid answer";
    else cout << "Cycle not found";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> " << dis[i] << endl;
    // }

    // printing edges
    // for(auto ed : edgeList) cout << ed.u << " " << ed.v << " " << ed.c << endl;

    /*
    int q;
    cin >> q;
    while (q--)
    {
        ll d;
        cin >> d;
        if(cycle) continue;
        if(dis[d] == inf) cout << "Not Possible" << "\n";
        else cout << dis[d] << "\n";
    }
    */

    return 0;
}
/*
Test Case-1
Input: 
3 3
0 1 -1
1 2 2
2 0 -3
Output:
Cycle found. No valid answer

Test Case-2
Input: 
4 4
0 2 5
0 3 12
2 1 2
1 3 3
Output: 
Cycle not found
*/
