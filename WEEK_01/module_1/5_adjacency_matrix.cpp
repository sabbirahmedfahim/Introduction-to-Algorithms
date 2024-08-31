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
        int a, b; cin >> a >> b;
        matrx[a][b] = 1;
        matrx[b][a] = 1; // In a directed graph, this line would not be written. #YouKHowWhy
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