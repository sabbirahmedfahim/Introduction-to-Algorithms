#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
ll dp[100000];
ll knapsack(ll arr[], ll n)
{
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    ll op1 = arr[n] + knapsack(arr, n-2);
    ll op2 = knapsack(arr, n-1);
    return dp[n] = max(op1, op2);
}
int main()
{
    int t; cin >> t;
    int cs = 1;
    while (t--)
    {
        ll n; cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << "Case " << cs++ << ": " << knapsack(arr, n-1) << nl; // selecting the value of n is crusial
    }

    return 0;
}