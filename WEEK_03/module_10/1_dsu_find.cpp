#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }
    // check the previous file to understand
    par[1] = 3; // the leader of 1 is 3
    par[2] = 1; // the leader of 2 is 1
}
int dsu_find(int node)
{
    if(par[node] == -1) return node;
    return dsu_find(par[node]);
    // in case you don't understand func calling, remember, it was (int node) and we're calling (int par[node])
}
int main()
{
    dsu_initialize(4);
    cout << "leader of " << 0 << " is: " << dsu_find(0) << endl;
    cout << "leader of " << 1 << " is: " << dsu_find(1) << endl;
    cout << "leader of " << 2 << " is: " << dsu_find(2) << endl;
    cout << "leader of " << 3 << " is: " << dsu_find(3) << endl;
    // check the previous file to understand

    return 0;
}