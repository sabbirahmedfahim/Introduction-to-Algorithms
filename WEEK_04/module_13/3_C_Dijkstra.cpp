// #include <bits/stdc++.h>
// using namespace std;
// const int N = 100;
// vector<pair<int, int>> v[N]; // node, weight(cost) pair
// int dis[N]; // dis-> distance
// class cmp // creating a compare class for sorting
// {
// public:
//     bool operator()(pair<int, int> a, pair<int, int> b)
//     {
//         return a.second > b.second; // true or false, return korbeiiii
//     }
// };
// void dijkstra(int src)
// {
//     priority_queue<pair<int, int>, vector < pair < int, int >>, cmp > pq; // represents priority queue (compare class added)
//     pq.push({src, 0});
//     dis[src] = 0;
//     // pair<int, int> parent = pq.top();
//     // cout << parent.first << " ";
//     while (!pq.empty())
//     {
//         pair<int, int> parent = pq.top();
//         pq.pop();
//         int node = parent.first;  // AKA nodeVal or parentNode
//         int cost = parent.second; // AKA parentCost
//         for (pair<int, int> child : v[node]) // range based for loop
//         {
//             int childNode = child.first;
//             int childCost = child.second;
//             if (cost + childCost < dis[childNode])
//             {
//                 // path relax
//                 // cout << childNode << " ";
//                 dis[childNode] = cost + childCost;
//                 pq.push({childNode, dis[childNode]}); // dis[childNode] bola r (cost+childCost) bola ekh kotha
//             }
//         }
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         int a, b, c; // c => cost
//         cin >> a >> b >> c;
//         v[a].push_back({b, c}); // as easy as you think. noting but an adj list
//         v[b].push_back({a, c});
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         dis[i] = INT_MAX;
//     }
//     dijkstra(1);
//     // cout << dis[n];
//     for (int i = 1; i <= n; i++)
//     {
//         cout << i << "-> " << dis[i] << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pi pair<ll, ll> // defined pair<ll, ll> as pi
#define nl '\n'
using namespace std;
const ll N = 1e5 + 5;
vector<pi> v[N];
ll dis[N];
ll par[N];
class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second; // don't understand
    }
};
void dijktra(int src)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pi parent = pq.top();
        pq.pop();
        ll parentNode = parent.first;
        ll parentCost = parent.second;
        for (pi child : v[parentNode])
        {
            ll childNode = child.first;
            ll childCost = child.second;
            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]});
                par[childNode] = parentNode;
            }
        }
    }
}
void print(int n)
{
    if (n == -1)
        return;
    print(par[n]);
    cout << n << " ";
}
int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 1e18;
        par[i] = -1;
    }

    dijktra(1);
    if(dis[n] == 1e18) cout << -1;
    else print(n); // instructor pushed values at a vector then prints in reverse order, i tried recursion instead

    return 0;
}