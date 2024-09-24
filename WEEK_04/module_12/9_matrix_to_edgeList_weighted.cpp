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
    int n;
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    // vector<pair<int, int>> edgeList;
    vector<Edge> edgeList;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(mat[i][j] > 0 && i!=j) 
            {
                edgeList.push_back(Edge(i, j, mat[i][j]));
            } 
        }
    }
    for(Edge edge : edgeList)
    {
        cout << edge.u << " " << edge.v << " " << edge.w << nl;
    }

    return 0;
}