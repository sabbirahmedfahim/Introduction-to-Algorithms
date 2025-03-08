#include <bits/stdc++.h>
#define nl '\n'
#define ll long long int
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
void divide(vector<int> &arr, int l, int r) // must watch/draw the recursive operations
{
    // for (int i = l; i <= r; i++)
    // {
    //     cout << arr[i] << ' ';
    // }
    // cout << nl;
    
    if(l < r)
    {
        int mid = (l+r)/2;
        divide(arr, l, mid);
        divide(arr, mid+1, r);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n = 6;
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    divide(arr, 0, n-1);

    // print(arr);

    return 0;
}