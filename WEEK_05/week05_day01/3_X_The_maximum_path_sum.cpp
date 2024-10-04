// accepted in online IDE and CF but not showing any output in the VS code
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
int n, m;
bool is_valid(int i, int j)
{
    return (i<=n && i>=1 && j <=m && j>=1);
}
int knapsack(int mat[][1001], int i, int j)
{
    if(mat[i][j] == mat[n][m]) return mat[n][m];
    if(is_valid(i+1, j) && is_valid(i, j+1))
    {
        int op1 = mat[i][j] + knapsack(mat, i+1, j);
        int op2 = mat[i][j] + knapsack(mat, i, j+1);    
        return max(op1, op2);
    }
    else if(is_valid(i+1, j)) return mat[i][j] + knapsack(mat, i+1, j);
    else if(is_valid(i, j+1)) return mat[i][j] + knapsack(mat, i, j+1);
}
int main()
{
    cin >> n >> m;
    // int mat[n+1][m+1];
    int mat[1001][1001];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << knapsack(mat, 1, 1);

    return 0;
}