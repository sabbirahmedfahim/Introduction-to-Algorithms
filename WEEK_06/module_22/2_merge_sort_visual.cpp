#include <bits/stdc++.h>
#define nl '\n'
#define ll long long int
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
void merge(vector<int> &arr, int l, int m, int r)
{
    int leftSz = m-l+1;
    int rightSz = r - m;
    int L[leftSz];
    int R[rightSz]; 
    
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

    int i = 0, j = 0;
    int cur = l; 
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
void merge_sort(vector<int> &arr, int l, int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);

        cout << "##########" << nl;
        for (int i = l; i <= mid; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << nl;
        for (int i = mid+1; i <= r; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << nl;
        
        // print without merge function and then with merge to understand ***
        // merge(arr, l, mid, r); // uncomment this
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n = 10;
    vector<int> arr = {15, 4, 3, 9, 2, 8, 10, 12, 6, 1};
    
    merge_sort(arr, 0, n-1);

    print(arr);

    return 0;
}