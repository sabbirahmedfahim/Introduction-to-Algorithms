// Problem link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
bool knapsack(ll data, ll n)
{
    if (data == n)
        return true;
    if(data > n) return false;
    if (data * 10 <= n)
    {
        ll op1 = knapsack(data * 10, n);
        ll op2 = knapsack(data * 20, n);
        return op1 || op2;
    }
    else
        return knapsack(data * 20, n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (knapsack(1, n) == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}

// instructor's code
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// ll input;

// bool rec(ll n)
// {
//     if(n > input)
//         return false;
//     if(n == input)
//         return true;
//     return rec(n*10) || rec(n*20);
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         cin >> input;
//         bool flag = rec(1);
//         if(flag)
//             cout << "YES\n";
//         else
//             cout << "NO\n";
//     }
// }