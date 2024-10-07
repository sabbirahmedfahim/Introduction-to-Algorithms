// Problem Link: https://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pi pair<int, int>
#define nl '\n'
using namespace std;
int n, e;
const ll INF = 1e18; // inf -> infinite

vector<pi> adj[100005];
ll dis[100005];
ll par[100005];
bool vis[100005];
void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[src] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq; // choto theke boro
    pq.push({dis[src], src});
    vis[src] = true;

    while (!pq.empty())
    {
        pi parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        int parentCost = parent.first;
        vis[parentNode] = true;

        for (pi child : adj[parentNode])
        {
            int childCost = child.first;
            int childNode = child.second;
            if (dis[parentNode] + childCost < dis[childNode])
            {
                dis[childNode] = dis[parentNode] + childCost;
                pq.push({dis[childNode], childNode});
                par[childNode] = parentNode;
            }
        }
    }
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    memset(par, -1, sizeof(par));
    memset(vis, false, sizeof(vis));
    int src = 1;
    dijkstra(src);
    if (!vis[n])
    {
        cout << -1 << nl;
    }
    else
    {
        vector<int> v;
        int current = n;
        while (true)
        {
            v.push_back(current);
            if (current == src) break;
            current = par[current];
        }

        reverse(v.begin(), v.end());

        for (int data : v) cout << data << " ";
    }

    return 0;
}