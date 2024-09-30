#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
// main theme is time complexity is very high
ll fibo(ll n) // O(N²)
{
    if(n==0 || n==1) return n;
    return fibo(n-1)+fibo(n-2); // O(N) * O(N) -> worst case
}
int main() // 0, 1, 1, 2, 3, 5, 8, 13, 21...
{
    ll n; cin >> n;
    cout << fibo(n); // n-> 0 based index value

    return 0;
}