// do not understand the approach
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int targetSum;
    cin >> targetSum;
    bool dp[n + 1][targetSum + 1];
    dp[0][0] = true;
    for (int i = 1; i <= targetSum; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= targetSum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]; // short-cut
                // bool op1 = dp[i - 1][j - arr[i - 1]]; // long-cut
                // bool op2 = dp[i - 1][j]; // long-cut
                // dp[i][j] = op1 || op2; // long-cut
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    if(dp[n][targetSum]) cout << "YES";
    else cout << "NO";

    return 0;
}