#include <bits/stdc++.h> // Edge, EdgeList, custom compare recap
#define ll long long int // goto next file after recaping
#define ull unsigned long long int
#define nl '\n'
using namespace std;
// mst -> Minimum Spanning Tree
class Edge
{
public:
    int u, v, w; // w for weight
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edgeList;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back((Edge(u, v, w)));
    }
    sort(edgeList.begin(), edgeList.end(), cmp); // comment this and them print to understand how it's working
    for (Edge ed : edgeList)
        cout << ed.u << " " << ed.v << " " << ed.w << nl;

    return 0;
}
/*
Input: 
5 7
0 1 2
0 2 3
0 3 3
3 4 6
2 4 4
2 1 7
1 4 5

Expected Output:
0 1 2
0 2 3
0 3 3
2 4 4
1 4 5
3 4 6
2 1 7

*/