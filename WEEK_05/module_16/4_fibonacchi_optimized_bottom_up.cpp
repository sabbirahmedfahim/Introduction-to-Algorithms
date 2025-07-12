// Bottom->up approach
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

int main()
{
    int n; cin >> n;
    ll arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    // No need for memoization since we are storing the values while iterating upwards (bottom-up approach)
    for (int i = 2; i <= n; i++) // O(N)
    {
        arr[i] = arr[i-2] + arr[i-1];
    }
    cout << arr[n];


    return 0;
}