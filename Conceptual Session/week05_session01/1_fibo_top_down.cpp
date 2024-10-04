#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
ll dp[100005];
ll fibo(ll n) // O(n)
{
    if(n==0 || n==1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibo(n-1) + fibo(n-2);
}
int main()
{
    ll n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo(n);

    return 0;
}