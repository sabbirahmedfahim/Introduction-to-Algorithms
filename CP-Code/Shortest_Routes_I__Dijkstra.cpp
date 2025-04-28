#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2E5 + 5;
vector<pair<int, int>> v[N];
ll dis[N];
void dijkstra(int src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // Min-heap by default
    pq.push({0, src});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<ll, ll> parent = pq.top();
        pq.pop();
        ll node = parent.second; // huh..
        ll cost = parent.first;

        if(cost > dis[node]) continue; // optimization

        for (pair<ll, ll> child : v[node])
        {
            ll childNode = child.first;
            ll childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                // vis[node] = true;
                dis[childNode] = cost + childCost;
                pq.push({dis[childNode], childNode}); // huh..
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1E18;
    }
 
    int sourceNode = 1;
    // cin >> sourceNode;
    dijkstra(sourceNode);
 
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     long long int d, dw;
    //     cin >> d >> dw;
    //     if (vis[d] && dis[d] <= dw)
    //         cout << "YES" << "\n";
    //     else
    //         cout << "NO" << "\n";
    // }
 
    return 0;
}