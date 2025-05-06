#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e; cin >> n >> e;
    vector<pair<int, int>> edges;
    while (e--)
    {
        int u, v; cin >> u >> v;
        edges.push_back({u, v}); 
    }
    
    for (int i = 0; i < edges.size(); i++)
    {
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    cout << endl;
    
    // use auto. don't worry, I know you are not auto pass :D
    for(auto edge : edges) cout << edge.first << " " << edge.second << endl;
    
    return 0;
}
/*
Input: 
6 6
0 1
1 5
0 4
0 3
3 4
2 4

Expected Output: 
0 1
1 5
0 4
0 3
3 4
2 4

0 1
1 5
0 4
0 3
3 4
2 4

*/