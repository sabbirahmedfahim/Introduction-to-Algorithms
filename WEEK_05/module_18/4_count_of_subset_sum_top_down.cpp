// i can also call it subset_recursion
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
int dp[1005][1005];
int subset_sum(int n, int arr[], int targetSum)
{
    if(n == 0)
    {
        if(targetSum == 0) return 1;
        else return 0;
    }
    if(dp[n][targetSum] != -1) return dp[n][targetSum];
    if(arr[n-1] <= targetSum)
    {
        int op1 = subset_sum(n-1, arr, targetSum-arr[n-1]);
        int op2 = subset_sum(n-1, arr, targetSum);
        return dp[n][targetSum] = op1 + op2;
    }
    else 
    {
        return dp[n][targetSum] = subset_sum(n-1, arr, targetSum);
    }
}
int main()
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }   
    int targetSum; cin >> targetSum;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= targetSum; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << subset_sum(n, arr, targetSum);


    return 0;
}