// LAW: fact(n) = n * fact(n-1)
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
int fact(int n) // O(N)
{
    if(n == 0) return 1;
    return n*fact(n-1);
}
int main() // There are no repeatition, no need for memorization (for optimization)
{ 
    int n; cin >> n;

    cout << fact(n);

    return 0;
}