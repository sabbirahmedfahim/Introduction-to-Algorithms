#include <bits/stdc++.h> // clean code
using namespace std;
char mat[25][25];
bool vis[25][25];
int row, col;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool is_valid(int ci, int cj)
{
    return (ci >= 0 && ci < row && cj >= 0 && cj < col);
}
int cnt = 0;
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++; // let's cnt++ here, it is dfs, your friend, it only checks valid & unique values hahaha
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(is_valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] != '#')
        {
            vis[ci][cj] = true;
            // cnt++; // it is valid but tested something different
            dfs(ci, cj);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int cs = 1; // case 1
    while (t--)
    {
        cin >> col >> row;
        int si, sj;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        dfs(si, sj);
        cout << "Case " << cs++ << ": " << cnt << endl; // new lesson: case++ hahaaha
        cnt = 0;
    }

    return 0;
}