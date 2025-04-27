#include <bits/stdc++.h> 
using namespace std;
const int N = 1e4+5;
char mat[N][N];
bool vis[N][N];
int n, m;
int si, sj, di, dj;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool is_valid(int ci, int cj)
{
    if (ci >= n || ci < 0 || cj >= m || cj < 0)
        return false;
    return true;
}
bool isFound = false;
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;  
        int cj = sj + d[i].second; 

        if (is_valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j]; 
        }
    }
    memset(vis, false, sizeof(vis));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == '.' && !vis[i][j])
            {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}