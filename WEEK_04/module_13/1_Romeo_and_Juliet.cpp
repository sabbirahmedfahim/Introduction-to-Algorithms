// instructors code (problemset is given at the website)
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
const int N = 1e5+5;
vector<int> v[N]; // ? array
bool vis[N]; // 1D array
int dis[N]; // 1D array
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
            }
        }
    }
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
    int src, des, k;
    cin >> src >> des >> k;
    bfs(src);
    if(dis[des] != -1 && dis[des] <= k*2) cout << "YES";
    else cout << "NO";

    return 0;
}

// failed attempt
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> v[1005];
// bool vis[1005];
// int level[1005];
// int parent[1005]; // parent, par variable are different
// void bfs(int src)
// {
//     queue<int> q;
//     q.push(src);
//     vis[src] = true;
//     level[src] = 0;
//     while (!q.empty())
//     {
//         int par = q.front();
//         q.pop();
//         for (int child : v[par])
//         {
//             if (vis[child] == false)
//             {
//                 q.push(child);
//                 vis[child] = true;
//                 level[child] = level[par] + 1;
//                 parent[child] = par; // parent, par variable are different
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
//     int src, des, steps;
//     cin >> src >> des >> steps;
//     steps*=2; // imagine why
//     memset(vis, false, sizeof(vis));
//     memset(level, -1, sizeof(level));
//     memset(parent, -1, sizeof(parent));
//     bfs(src);
//     int temp = des;
//     int totalSteps = 0;
//     while (temp != -1)
//     {
//         // cout << temp << endl;
//         totalSteps++;
//         temp = parent[temp];
//     }
//     totalSteps--; // think why

//     if(totalSteps <= steps && vis[des]) cout << "YES";
//     else cout << "NO";
    
//     return 0;
// }