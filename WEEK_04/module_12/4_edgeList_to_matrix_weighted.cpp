// easyest
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

int main()
{
    int n, e; cin >> n >> e;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = -1;
            if(i==j) mat[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b, c; cin >> a >> b >> c;
        // mat[a][b] = 1;
        // mat[b][a] = 1;
        mat[a][b] = c;
        mat[b][a] = c;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}