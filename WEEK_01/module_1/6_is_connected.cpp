#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int matrx[n][n];
    memset(matrx, 0, sizeof(matrx));
    while (e--)
    {
        int a, b; cin >> a >> b;
        matrx[a][b] = 1;
        matrx[b][a] = 1;
    }
    if(matrx[3][4] == 1) cout << "connected" << endl;
    else cout << "not connected" << endl;

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
connected

*/