#include <bits/stdc++.h> // 3-6 DFS on 2D Animated(MUST WATCH)
// goto next for clean code
using namespace std;
char arr[20][20];
bool vis[20][20];
int n, m;
vector<pair<int, int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};
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
        // we hafta check corner cases
        int ci = si+d[i].first; // i-th index of children
        // int cj = si+d[i].second; // search for MISTAKE
        int cj = sj+d[i].second; // j-th index of children
        // cout << ci << " " << cj << endl; // print to understand
        // cout << d[i].first << " " << d[i].second << endl; // print to understand
        
        // if(!vis[ci][cj] && is_valid(ci, cj)) // WRONG: You will get an ERROR! (imagine why) // because of Invalid Index
        if (is_valid(ci, cj) && !vis[ci][cj]) // we hafta check corner cases
        {
            dfs(ci, cj);
        }
    }
}   
int main()
{
    // int n, m; // deslared globally
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