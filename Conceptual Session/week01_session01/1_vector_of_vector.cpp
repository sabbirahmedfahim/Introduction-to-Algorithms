#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

int main()
{
    // type-1
    vector<vector<int>> v1; // row, column dynamic so we can add anything at any position
    v1.push_back(vector<int> ({1,2,3}));
    v1.push_back(vector<int> ({4,5,6}));
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            cout << v1[i][j] << " ";
        }
        cout << nl;
    }
    cout << "size of row: " << v1.size() << nl;
    cout << "size of col: " << v1[0].size() << nl;
    v1[0].push_back(7); // added column !! [benefit of dynamic array]
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            cout << v1[i][j] << " ";
        }
        cout << nl;
    }

    // type-2
    vector<vector<int>> v2;

    return 0;
}