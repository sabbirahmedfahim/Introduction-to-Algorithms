#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    // int arr[n];
    // vector<int> matrx(n); // WRONG // it's a 1D array
    vector<int> matrx[n]; // matrx is a 2D array 
    while (e--)
    {
        int a, b; cin >> a >> b;
        matrx[a].push_back(b);
        matrx[b].push_back(a); // In a directed graph, this line would not be written. #YouKHowWhy
    }
    for (int i = 0; i < matrx[0].size(); i++)
    {
        cout << matrx[0][i] << " ";
    }
    cout << endl << endl;
    
    for(int data : matrx[0]) cout << data << " "; // range based for loop
    cout << endl;
    for(int data : matrx[4]) cout << data << " "; // range based for loop


    return 0;
}