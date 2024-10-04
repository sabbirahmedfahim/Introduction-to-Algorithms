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
    int sumOfElements = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sumOfElements += arr[i];
    }
    bool dp[n + 1][sumOfElements + 1];
    dp[0][0] = true;
    for (int i = 1; i <= sumOfElements; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sumOfElements; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // for (int i = 0; i <= n; i++) // print the matrix
    // {
    //     for (int j = 0; j <= sumOfElements; j++)
    //     {
    //         if(dp[i][j] == 1) cout << j << " "; // to see eligible data's
    //         else cout << dp[i][j] << " ";
    //         if(dp[i][j] == 1) v.push_back(j);
    //     }
    //     cout << nl;
    // }
    vector<int> v;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sumOfElements; j++)
        {
            if (dp[i][j] == 1) v.push_back(j);
        }
    }
    int ans = INT_MAX;
    for (int data : v)
    {
        int s1 = data;
        // int s2 = s1 - s2;
        int s2 = sumOfElements - s1;
        ans = min(ans, abs(s1 - s2));
    }
    cout << ans;

    return 0;
}