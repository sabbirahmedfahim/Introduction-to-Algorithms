#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

int main()
{
    int n; cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int W; cin >> W;
    int dp[n+1][W+1]; // u have to understand why size+1 [watch module]
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if(i==0 || j==0) dp[i][j] = 0; // relate something? if(i==0 || W==0) return 0
        }
    }
    for (int i = 1; i <= n; i++) // O(n * W)
    {
        for (int j = 1; j <= W; j++) // O(n)
        {
            if(weight[i-1] <= j) // relate something? if(weight[n-1] <= W)
            {
                int op1 = dp[i-1][j-weight[i-1]]+value[i-1];
                int op2 = dp[i-1][j];
                dp[i][j] = max(op1, op2);
            }
            else
            {
                int op2 = dp[i-1][j];
                dp[i][j] = op2;
            }
        }
    }
    // for (int i = 0; i <= n; i++) // print
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    cout << dp[n][W];

    return 0;
}