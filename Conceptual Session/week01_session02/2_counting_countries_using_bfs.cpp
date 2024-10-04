#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
const int N = 1e3;
int n, m;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
char graph[N][N];
bool vis[N][N];
bool is_valid(int ci, int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < m);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int nrow = par.first;
        int ncol = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = nrow + d[i].first;
            int cj = ncol + d[i].second;
            if (is_valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] == '.')
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    // . -> land
    // ~ -> water
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && graph[i][j] == '.')
            {
                cnt++;
                bfs(i, j);
            }
        }
    }

    cout << cnt;

    return 0;
}