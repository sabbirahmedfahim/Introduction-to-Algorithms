// recursive approach
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
const ll N = 1e6+5;
ll dp[N];
ll fibo(ll n) // O(n)
{
    if(n == 0 || n == 1) return n;

    if(dp[n] != -1) return dp[n]; // if the answer is saved, reduce the operation hahaha
    return dp[n] = fibo(n - 1) + fibo(n - 2); // memorization
}
int main() 
{
    memset(dp, -1, sizeof(dp)); 
    ll n; cin >> n;
    cout << fibo(n) << nl;

    return 0;
}
/*
✅ denotes memorization was used to reduce complexity

                             fibo(7)
                             /      \
                        fibo(6)     fibo(5) ✅
                        /     \
                  fibo(5) ✅   fibo(4) ✅
                                 /      \
                           fibo(3) ✅   fibo(2) ✅
                           /     \
                     fibo(2) ✅  fibo(1) ✅
                     /     \
               fibo(1) ✅  fibo(0) ✅
*/