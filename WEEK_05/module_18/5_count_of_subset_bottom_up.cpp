// do not understand the approach
// they says bottom-up approach then why recursion is used?
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int subset_sum(int n, int a[], int targetSum)
{
    if (n == 0)
    {
        if (targetSum == 0)
            return 1;
        else
            return 0;
    }
    if (dp[n][targetSum] != -1)
        return dp[n][targetSum];
    if (a[n - 1] <= targetSum)
    {
        int op1 = subset_sum(n - 1, a, targetSum - a[n - 1]);
        int op2 = subset_sum(n - 1, a, targetSum);
        return dp[n][targetSum] = op1 + op2;
    }
    else
    {
        return dp[n][targetSum] = subset_sum(n - 1, a, targetSum);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int targetSum;
    cin >> targetSum;
    dp[0][0] = true;
    for (int i = 1; i <= targetSum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= targetSum; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= targetSum; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][targetSum];

    return 0;
}