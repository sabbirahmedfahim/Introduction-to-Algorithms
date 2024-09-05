#include <bits/stdc++.h> // goto next for clean code
using namespace std;
bool vis[20][20];
int dis[20][20];
char arr[20][20];
int n, m;
// vector<int> v[100]; // 2D
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
    // vis[{si, sj}] = true; // WRONG
    vis[si][sj] = true;
    dis[si][sj] = 0; // initially -1 but distance 0 why?
    while (!q.empty())
    {
        // int par = q.front();
        pair<int, int> par = q.front();
        q.pop();
        cout << par.first << " " << par.second << endl;
        for (int i = 0; i < 4; i++)
        {
            // int ci = si + d[i].first;  
            // int cj = sj + d[i].second; 
            int ci = par.first + d[i].first;  // i-th index of children
            int cj = par.second + d[i].second; // j-th index of children

            if (is_valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second]+1;
                // bfs(ci, cj); // WRONG
            }
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
    memset(dis, -1, sizeof(dis)); // initially -1
    // bfs(0);
    bfs(si, sj);

    return 0;
}