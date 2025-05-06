#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e; // n -> nodes, e -> edges
    cin >> n >> e;
    // int matrx[n][n] = {0}; // not possible
    int matrx[n][n];
    memset(matrx, 0, sizeof(matrx)); // initialized all index with value 0
   
    while (e--)
    {
        int u, v; cin >> u >> v;
        matrx[u][v] = 1;
        matrx[v][u] = 1; // for undirected graph
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrx[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
/*
Input:
6 6
0 1
1 5
0 4
0 3
3 4
2 4

Expected Output: 
0 1 0 1 1 0 
1 0 0 0 0 1 
0 0 0 0 1 0 
1 0 0 0 1 0 
1 0 1 1 0 0 
0 1 0 0 0 0 
*/