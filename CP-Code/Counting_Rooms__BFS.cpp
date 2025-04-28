#include <bits/stdc++.h> 
using namespace std;
bool vis[1005][1005];
char mat[1005][1005];
int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool is_valid(int ci, int cj)
{
    if (ci >= n || ci < 0 || cj >= m || cj < 0)
        return false;
    return true;
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
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first; 
            int cj = par.second + d[i].second; 

            if (is_valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] == '.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    bfs(si, sj);
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && mat[i][j] == '.')
            {
                cnt++;
                bfs(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}