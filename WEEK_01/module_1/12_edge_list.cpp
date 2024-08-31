#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e; cin >> n >> e;
    // pair<int, int> a[e];
    vector<pair<int, int>> v; // every index of vector has pair of two int
    while (e--)
    {
        int a, b; cin >> a >> b;
        // v.push_back(make_pair(a, b)); // accurate
        v.push_back({a, b});  // shortcut
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;

    // range based for loop
    for(pair<int, int> p : v) cout << p.first << " " << p.second << endl;
    cout << endl;
    
    // use auto. don't worry, I know you are not auto pass :D
    for(auto p : v) cout << p.first << " " << p.second << endl;
    

    return 0;
}