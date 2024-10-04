#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
const int N = 1e5+5;
int main()
{
    vector<int> v[N]; // hurreh! so it's array of vector I use regularly !!
    vector<int> arr[2]; // row-> static; col-> dynamic
    arr[0].push_back(1);
    arr[0].push_back(2);
    arr[0].push_back(3);
    arr[0].push_back(4);

    arr[1].push_back(5);
    arr[1].push_back(6);
    arr[1].push_back(7);
    arr[1].push_back(8);
    for (int i = 0; i < 2; i++) // ekhane arr.size() shows error because arr.size() is STL of vector 
    {
        for (int j = 0; j < arr[i].size(); j++) // ekhane arr[i].size() working because col are dynamic
        {
            cout << arr[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;

    arr[0].push_back(100); // added column because columns are dynamic
    arr[0].push_back(300); // added column because columns are dynamic
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << nl;
    }
    

    return 0;
}