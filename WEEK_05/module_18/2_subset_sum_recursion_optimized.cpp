// i can also call it subset_sum_top_down
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
int dp[1005][1005]; 
bool subset_sum(int n, int a[], int targetSum) // n, targetSum both will change
{
    if(n == -1) return targetSum == 0;

    if(dp[n][targetSum] != -1) return dp[n][targetSum];

    if(a[n] <= targetSum)
    {
        bool op1 = subset_sum(n-1, a, targetSum - a[n]);
        bool op2 = subset_sum(n-1, a, targetSum);
        return dp[n][targetSum] = op1 || op2;
    }
    else 
    {
        return dp[n][targetSum] = subset_sum(n-1, a, targetSum);
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
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= targetSum; j++)
        {
            dp[i][j] = -1;
        }
    }
    if(subset_sum(n - 1, a, targetSum)) cout << "YES";
    else cout << "NO";


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