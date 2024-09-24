// you should understand why edge count is 5 on TC 1 rather than 4
#include <bits/stdc++.h> // for WEIGHTED graph
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
// void convert_adj_list_to_matrix(int n, vector<int> adj[])
void convert_adj_list_to_matrix(int n, vector<pair<int, int>> adj[])
{
    int mat[n][n];
    // memset(mat, 0, sizeof(mat));
    for (int i = 0; i < n; i++)
    {
         for (int j = 0; j < n; j++)
        {
            mat[i][j] = -1; // asha jay na
            if(i==j) mat[i][j] = 0; // diagonal borabor zero cost
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(pair<int, int> child : adj[i])
        {
            int childNode = child.first;
            int cost = child.second;
            mat[i][childNode] = {cost};
        }
    }
     for (int i = 0; i < n; i++)
    {
         for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> v[n];
    while (e--)
    {
        int a, b, c; // c for cost
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        // v[b].push_back(a);
    }
    convert_adj_list_to_matrix(n, v);

    return 0;
}