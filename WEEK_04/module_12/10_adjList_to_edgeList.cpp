#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> v[n];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c}); // directed graph
    }
    // for (int i = 0; i < n; i++) // prove that it's an adjList
    // {
    //     cout << i << "-> ";
    //     for (pair<int, int> child : v[i])
    //     {
    //         cout << "{" << child.first << ", " << child.second << "} ";
    //     }
    //     cout << nl;
    // }
    vector<Edge> edgeList;
    for (int i = 0; i < n; i++)
    {
        for(pair<int, int> child : v[i])
        {
            int childNode = child.first;
            int childCost = child.second;
            // edgeList.push_back({childNode, childCost}); // wrong
            edgeList.push_back(Edge(i, childNode, childCost));
        }
    }
    for(auto edge : edgeList)
    {
        cout << edge.u << " " << edge.v << " " << edge.w << nl;
    }
    

    return 0;
}