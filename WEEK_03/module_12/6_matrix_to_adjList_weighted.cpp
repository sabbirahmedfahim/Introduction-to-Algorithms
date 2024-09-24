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
    vector<pair<int, int>> v[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // notice the condition : data > 0
            if(mat[i][j] > 0 && i != j) v[i].push_back({j, mat[i][j]}); // mat[i][j] e tar cost 
        }
    }
    for (int i = 0; i < n; i++) // output
    {
        cout << i << "-> ";
        for(pair<int, int> child : v[i]) 
        {
            cout << "{" << child.first << ", " << child.second << "} ";
        }
        cout << nl;
    }

    return 0;
}