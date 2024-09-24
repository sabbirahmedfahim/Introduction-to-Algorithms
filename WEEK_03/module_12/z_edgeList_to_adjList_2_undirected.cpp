#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n][n];
    // memset(mat, 0, sizeof(mat));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = -1; // -1 mane jawa jay na
            if(i==j) mat[i][j] = 0; 
        }
    }
    
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = c;
        mat[b][a] = c; // for the directed version, just remove the line
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << nl;
    }

    return 0;
}