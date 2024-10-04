#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

vector<int> arr[100]; // array of vector
int main()
{
    int n, e; cin >> n >> e;
    while (e--)
    {
        int a, b; cin >> a >> b;
        arr[a].push_back(b); // now I understand the dynamic allowcation of array of vector
        arr[b].push_back(a); 
    }
    // arr[0].push_back(33); // comment-out this to understand more 
    for (int i = 0; i < n; i++)
    {
        cout << i << "--> ";
        for (int j = 0; j < arr[i].size(); j++) // i should understand it clearly, explained earlier check prev files
        {
            cout << arr[i][j] << " ";
        }
        cout << nl;
    }
    

    return 0;
}