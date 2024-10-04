// i can also call it subset_sum_top_down
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
int dp[1005][1005];
bool subset_sum(int n, int arr[], int targetSum)
{
    if(n == 0)
    {
        if(targetSum == 0) return true;
        else return false;
    }
    if(dp[n][targetSum] != -1) return dp[n][targetSum];
    if(arr[n-1] <= targetSum)
    {
        bool op1 = subset_sum(n-1, arr, targetSum-arr[n-1]);
        bool op2 = subset_sum(n-1, arr, targetSum);
        return dp[n][targetSum] = op1 || op2;
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
    if(subset_sum(n, arr, targetSum)) cout << "YES";
    else cout << "NO";


    return 0;
}