#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> matrx[n]; // matrx is u 2D array 
    while (e--)
    {
        int u, v; cin >> u >> v;
        matrx[u].push_back(v);
        matrx[v].push_back(u); // for undirected graph
    }
    for (int i = 0; i < matrx[0].size(); i++)
    {
        cout << matrx[0][i] << " ";
    }

    cout << endl << endl;
    
    for(int data : matrx[0]) cout << data << " "; cout << endl; 
    for(int data : matrx[4]) cout << data << " "; cout << endl;

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
1 4 3 

1 4 3 
0 3 2 

*/