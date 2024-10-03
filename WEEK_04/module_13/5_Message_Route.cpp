#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
const int N = 1e5+5;
vector<int> v[N]; // ? array
bool vis[N]; // 1D array
int dis[N]; // 1D array
int parent[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : v[par])
        {
            if(!vis[child])
            {
                vis[child] = true;
                q.push(child);
                dis[child] = dis[par]+1;
                parent[child] = par;
            }
        }
    }
}
void print(int n)
{
    if (n == -1)
        return;
    print(parent[n]);
    cout << n << " ";
}
int main()
{
    int n, e; cin >> n >> e;

    while (e--)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(parent, -1, sizeof(dis));
    bfs(1);
    if(dis[n] == -1) cout << "IMPOSSIBLE";
    else 
    {
        cout << dis[n]+1 << nl;
        print(n);
    }


    return 0;
}

// instructor's code (efficient-> he removed distance array)
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// vector<int> v[N];
// bool vis[N];
// int parent[N];
// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     vis[s] = true;
//     while (!q.empty())
//     {
//         int par = q.front();
//         q.pop();
//         for (int child : v[par])
//         {
//             if (!vis[child])
//             {
//                 vis[child] = true;
//                 q.push(child);
//                 parent[child] = par;
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
//         int a, b;
//         cin >> a >> b;
//         v[a].push_back(b);
//         v[b].push_back(a);
//     }
//     memset(vis, false, sizeof(vis));
//     memset(parent, -1, sizeof(parent));
//     bfs(1);
//     int x = n;
//     vector<int> path;
//     while (x != -1)
//     {
//         path.push_back(x);
//         x = parent[x];
//     }
//     reverse(path.begin(), path.end());
//     // do not understand next lines
//     if (path.size() == 1)
//         cout << "IMPOSSIBLE" << endl;
//     else
//     {
//         cout << path.size() << endl;
//         for (int val : path)
//             cout << val << " ";
//         cout << endl;
//     }
//     return 0;
// }