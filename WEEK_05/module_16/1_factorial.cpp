// LAW: fact(n) = n * fact(n-1)
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

// There is no repeatition, no need for memorization (for optimization)
int fact(int n) // O(n)
{
    if(n == 0) return 1;
    return n*fact(n-1);
}
int main() 
{ 
    int n; cin >> n;

    cout << fact(n);

    return 0;
}