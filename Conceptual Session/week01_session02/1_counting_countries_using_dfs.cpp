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
    return (ci>=0 && ci<n && cj>=0 && cj<m);
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first; // row er move
        int cj = sj + d[i].second; // col er move
        if(is_valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    // . -> land
    // ~ -> water
    cin >> n >> m;
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && graph[i][j] == '.')
            {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt;
    

    return 0;
}