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
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(mat[i][j] == 1 && i != j) 
            {
                edgeList.push_back({i, j});
            } 
        }
    }
    for(pair<int, int> edge : edgeList)
    {
        cout << edge.first << " " << edge.second << nl;
    }

    return 0;
}