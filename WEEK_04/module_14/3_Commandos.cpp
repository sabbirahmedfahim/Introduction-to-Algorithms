#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
const int N = 105;
vector<int> v[N]; // adj list
int dis_From_Src[N];
int dis_From_Des[N];
bool vis[N];
void bfs(int s, int track)
{
    queue<int> q;
    q.push(s);
    if (track == 1)
        dis_From_Src[s] = 0;
    else
        dis_From_Des[s] = 0;
    vis[s] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                if (track == 1)
                    dis_From_Src[child] = dis_From_Src[par] + 1;
                else
                    dis_From_Des[child] = dis_From_Des[par] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        int n, e; cin >> n >> e;
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int src, des;
        cin >> src >> des;
        memset(vis, false, sizeof(vis));
        memset(dis_From_Src, -1, sizeof(dis_From_Src));
        bfs(src, 1); // 1 and 2 has no connection with main code, there're just for leveling

        memset(vis, false, sizeof(vis));
        memset(dis_From_Des, -1, sizeof(dis_From_Des));
        bfs(des, 2); // 1 and 2 has no connection with main code, there're just for leveling
        int maxDis = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxDis = max(maxDis, dis_From_Src[i]+dis_From_Des[i]);
        }
        cout << "Case " << cs++ << ": " << maxDis << nl;
        for (int i = 0; i < n; i++) // most significant part of the problem (YOU MUST UNDERSTAND)
        {
            v[i].clear();
        }
    }

    return 0;
}