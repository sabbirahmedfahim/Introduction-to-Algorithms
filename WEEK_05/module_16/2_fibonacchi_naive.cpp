#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

ll fibo(ll n) // O(2ⁿ)
{
    if(n == 0 || n == 1) return n;
    // cout << n-1 << " " << n-2 << nl;
    return fibo(n-1) + fibo(n-2); 
}
int main() // 0, 1, 1, 2, 3, 5, 8, 13, 21...
{
    ll n; cin >> n;
    cout << fibo(n) << nl; // n-> 0 based index value

    return 0;
}
/*
a recursion tree to visualize why the time complexity is approximately O(2ⁿ).

                                fibo(5)              -> 1
                               /       \
                          fibo(4)     fibo(3)        -> 2
                         /      \     /     \
                  fibo(3)  fibo(2) fibo(2) fibo(1)   -> 4
                 /     \    /   \   /   \
           fibo(2) fibo(1) fibo(1) fibo(0)           -> 8 (max)
          /     \
    fibo(1) fibo(0)                                  -> 16 (max)
*/
/*
Start: call fibo(5)
Stack:
[fibo(5)]                ← calls fibo(4), waits

  fibo(5) calls fibo(4)
Stack:
[fibo(5)]                ← waiting for fibo(4)
[fibo(4)]                ← calls fibo(3), waits

    fibo(4) calls fibo(3)
Stack:
[fibo(5)]
[fibo(4)]                ← waiting for fibo(3)
[fibo(3)]                ← calls fibo(2), waits

      fibo(3) calls fibo(2)
Stack:
[fibo(5)]
[fibo(4)]
[fibo(3)]                ← waiting for fibo(2)
[fibo(2)]                ← calls fibo(1), waits

        fibo(2) calls fibo(1)
Stack:
[fibo(5)]
[fibo(4)]
[fibo(3)]
[fibo(2)]                ← waiting for fibo(1)
[fibo(1)]                ← base case, returns 1 immediately

        fibo(1) returns 1
Stack:
[fibo(5)]
[fibo(4)]
[fibo(3)]
[fibo(2)]                ← resumes, calls fibo(0)

        fibo(2) calls fibo(0)
Stack:
[fibo(5)]
[fibo(4)]
[fibo(3)]
[fibo(2)]                ← waiting for fibo(0)
[fibo(0)]                ← base case, returns 0 immediately

        fibo(0) returns 0
Stack:
[fibo(5)]
[fibo(4)]
[fibo(3)]
[fibo(2)]                ← fibo(2) computes 1 + 0 = 1, returns 1

      fibo(2) returns 1
Stack:
[fibo(5)]
[fibo(4)]
[fibo(3)]                ← resumes, calls fibo(1)

      fibo(3) calls fibo(1)
Stack:
[fibo(5)]
[fibo(4)]
[fibo(3)]                ← waiting for fibo(1)
[fibo(1)]                ← base case, returns 1 immediately

      fibo(1) returns 1
Stack:
[fibo(5)]
[fibo(4)]
[fibo(3)]                ← fibo(3) computes 1 + 1 = 2, returns 2

    fibo(3) returns 2
Stack:
[fibo(5)]
[fibo(4)]                ← resumes, calls fibo(2)

    fibo(4) calls fibo(2)
Stack:
[fibo(5)]
[fibo(4)]                ← waiting for fibo(2)
[fibo(2)]                ← calls fibo(1), waits

      fibo(2) calls fibo(1)
Stack:
[fibo(5)]
[fibo(4)]
[fibo(2)]                ← waiting for fibo(1)
[fibo(1)]                ← base case, returns 1 immediately

      fibo(1) returns 1
Stack:
[fibo(5)]
[fibo(4)]
[fibo(2)]                ← resumes, calls fibo(0)

      fibo(2) calls fibo(0)
Stack:
[fibo(5)]
[fibo(4)]
[fibo(2)]                ← waiting for fibo(0)
[fibo(0)]                ← base case, returns 0 immediately

      fibo(0) returns 0
Stack:
[fibo(5)]
[fibo(4)]
[fibo(2)]                ← fibo(2) computes 1 + 0 = 1, returns 1

    fibo(2) returns 1
Stack:
[fibo(5)]
[fibo(4)]                ← fibo(4) computes 2 + 1 = 3, returns 3

  fibo(4) returns 3
Stack:
[fibo(5)]                ← resumes, calls fibo(3)

  fibo(5) calls fibo(3)
Stack:
[fibo(5)]                ← waiting for fibo(3)
[fibo(3)]                ← calls fibo(2), waits

    fibo(3) calls fibo(2)
Stack:
[fibo(5)]
[fibo(3)]                ← waiting for fibo(2)
[fibo(2)]                ← calls fibo(1), waits

      fibo(2) calls fibo(1)
Stack:
[fibo(5)]
[fibo(3)]
[fibo(2)]                ← waiting for fibo(1)
[fibo(1)]                ← base case, returns 1 immediately

      fibo(1) returns 1
Stack:
[fibo(5)]
[fibo(3)]
[fibo(2)]                ← resumes, calls fibo(0)

      fibo(2) calls fibo(0)
Stack:
[fibo(5)]
[fibo(3)]
[fibo(2)]                ← waiting for fibo(0)
[fibo(0)]                ← base case, returns 0 immediately

      fibo(0) returns 0
Stack:
[fibo(5)]
[fibo(3)]
[fibo(2)]                ← fibo(2) computes 1 + 0 = 1, returns 1

    fibo(2) returns 1
Stack:
[fibo(5)]
[fibo(3)]                ← resumes, calls fibo(1)

    fibo(3) calls fibo(1)
Stack:
[fibo(5)]
[fibo(3)]
[fibo(1)]                ← base case, returns 1 immediately

    fibo(1) returns 1
Stack:
[fibo(5)]
[fibo(3)]                ← fibo(3) computes 1 + 1 = 2, returns 2

  fibo(3) returns 2
Stack:
[fibo(5)]                ← fibo(5) computes 3 + 2 = 5, returns 5

fibo(5) returns 5
Stack:
[]                      ← stack empty, program ends
*/