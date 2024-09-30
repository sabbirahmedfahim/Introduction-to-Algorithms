// this approach is also told as Top-down approach, recursion e upor theke nicher dike jai. 
// Top->down
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
const ll N = 1e6+5;
ll dp[N];
ll fibo(ll n) // O(N)
{
    if(n==0 || n==1) return n;
    if(dp[n] != -1) return dp[n]; // if the answer is saved, reduce the operation hahaha
    dp[n] = fibo(n-1)+fibo(n-2); // Memoization on Fibonacci Series (answer save kore rakhsi)
    return fibo(n-1)+fibo(n-2); 
}
int main() // power of dynamic programming
{
    memset(dp, -1, sizeof(dp)); 
    ll n; cin >> n;
    cout << fibo(n); // n-> 0 based index value

    return 0;
}