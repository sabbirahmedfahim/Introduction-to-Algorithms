#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;
char mat[50][50];
bool vis[50][50];
int dis[50][50];
vector<pair<int, int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};
int n;
bool valid(int ci, int cj)
{
    return (ci>=0 && ci<n && cj>=0 && cj<n);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] != 'T') 
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second]+1;
            }
        }
    }
}
int main()
{
    // int n; cin >> n;

    while (cin >> n) // EOF
    {
        int si, sj, di, dj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
                if(mat[i][j] == 'S') 
                {
                    si = i;
                    sj = j;
                }
                if(mat[i][j] == 'E') 
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[di][dj] << nl;
    }


    return 0;
}