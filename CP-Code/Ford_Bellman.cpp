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
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf; 
    }

    dis[1] = 0; // fixed the source value

    for (int i = 1; i <= n; i++) // O(V*E)
    {
        for (Edge ed : edgeList) // O(E)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < inf && dis[u] + c < dis[v]) // for min score
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    /* it is confirmed in the problem statement that there is no cycles of negative weights */ 
    // bool isCycle = false;
    // for (Edge ed : edgeList) // It's exactly N times we're executing edgeList to detect cycle
    // {
    //     int u, v, c;
    //     u = ed.u;
    //     v = ed.v;
    //     c = ed.c;
    //     if (dis[u] < inf && dis[u] + c < dis[v]) // for min score
    //     {
    //         isCycle = true;
    //         break;
    //         dis[v] = dis[u] + c;
    //     }   
    // }
    // if(isCycle) cout << -1 << endl;
    // else cout << dis[n] << endl;
    /* it is confirmed in the problem statement that there is no cycles of negative weights */ 

    for (int i = 1; i <= n; i++)
    {
        if(dis[i] == inf) cout << 30000 << " "; // this is told is the statement
        else cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}