#include <bits/stdc++.h> // clean code
using namespace std;
char arr[20][20];
bool vis[20][20];
int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool is_valid(int ci, int cj)
{
    if (ci >= n || ci < 0 || cj >= m || cj < 0)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;  // i-th index of children
        int cj = sj + d[i].second; // j-th index of children

        if (is_valid(ci, cj) && !vis[ci][cj])
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
            cin >> arr[i][j];
        }
    }
    int si; // si -> i-th index of source
    int sj; // sj -> j-th index of source
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    dfs(si, sj); // x axis, y axis

    return 0;
}