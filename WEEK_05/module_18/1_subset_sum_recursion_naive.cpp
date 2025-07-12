// recursive approach
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

// It builds a binary recursion tree with 2 branches per node, and height n.
bool subset_sum(int n, int a[], int targetSum) // O(2ⁿ)
{
    if(n == -1)
    {
        if(targetSum == 0) return true;
        else return false;
    }

    if(a[n] <= targetSum)
    {
        bool op1 = subset_sum(n-1, a, targetSum - a[n]); // nibo
        bool op2 = subset_sum(n-1, a, targetSum); // nibo na
        return op1 || op2;
    }
    else 
    {
        return subset_sum(n-1, a, targetSum); // nibo na
    }
}
int main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int targetSum; cin >> targetSum;
    if(subset_sum(n - 1, a, targetSum)) cout << "YES" << nl;
    else cout << "NO" << nl;


    return 0;
}
/*
Input:
4
1 2 4 6
7
Output: 
YES
*/

// tips: use https://recursion.vercel.app/ to simulate the process

/*
                        subset_sum(3, 7)
                        /               \
        subset_sum(2, 7)                 subset_sum(2, 1)
           /         \                      /         \
  subset_sum(1, 7)   subset_sum(1, 3)   subset_sum(1, -3)   subset_sum(1, 1)
       /     \          /     \                                 /      \
ss(0,7)   ss(0,5)   ss(0,3)  ss(0,1)                       ss(0,-1)   ss(0,1)
                                   \                                  /     \
                             ✅ ss(-1,0)                        ss(-1,1)  ✅ ss(-1,0)
*/