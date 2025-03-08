// merge two arrays
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long int
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
/*
let, {2, 3, 5, 10} and {1, 4, 6, 8, 9, 15} are two arrays, we're gonna merge it
*/
void merge(vector<int> &arr, int l, int m, int r)
{
    int leftSz = m-l+1;
    int rightSz = r - m;
    int L[leftSz]; // making duplicate array
    int R[rightSz]; // making duplicate array
    
    int idx = 0;
    for (int i = l; i <= m; i++)
    {
        L[idx] = arr[i];
        idx++;
    }
    idx = 0; 
    for (int i = m+1; i <= r; i++)
    {
        R[idx] = arr[i];
        idx++;
    }

    // for (int i = l; i <= m; i++) cout << L[i] << ' '; // it works
    // cout << nl;

    int i = 0, j = 0;
    int cur = l; // ***
    while (i < leftSz && j < rightSz)
    {
        if(L[i] <= R[j])    
        {
            arr[cur] = L[i];
            i++;
        }
        else 
        {
            arr[cur] = R[j];
            j++;
        }
        cur++;
    }

    while (i < leftSz) arr[cur] = L[i], i++, cur++;
    while (j < rightSz) arr[cur] = R[j], j++, cur++;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n = 10;
    vector<int> arr = {2, 3, 5, 10, 1, 4, 6, 8, 9, 15};
    merge(arr, 0, 3, n-1); // 3 because the value of arr[3] = 10 [look at the tc]

    print(arr);

    return 0;
}