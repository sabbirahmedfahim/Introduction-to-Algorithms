#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

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
    vector<int> v[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(mat[i][j] == 1) v[i].push_back(j); // yeeees
        }
    }
    for (int i = 0; i < n; i++) // output
    {
        cout << i << "-> ";
        for(int child : v[i]) 
        {
            cout << child << " ";
        }
        cout << nl;
    }

    return 0;
}