#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
int knapsack(int n, int weight[], int value[], int W)
{
    if(n == 0 || W == 0) return 0; // smallest invalid input
    if(weight[n-1] <= W)
    {
        // duita option (based on weight)
        // niye dekhbo, na niye dekhbo
        int op1 = knapsack(n-1, weight, value, W-weight[n-1]) + value[n-1];
        int op2 = knapsack(n-1, weight, value, W); 
        return max(op1, op2); 
    }
    else 
    {
        // ekta option (based on weight)
        // na niye dekhte hobe
        int op2 = knapsack(n-1, weight, value, W);
        return op2;
    }
}
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
    int W; cin >> W; // weight of knapsack, imagine a plastic-bag size
    cout << knapsack(n, weight, value, W); // array size, weight array, value array, total weight

    return 0;
}