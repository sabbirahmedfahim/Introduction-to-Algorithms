#include <bits/stdc++.h>
#define nl '\n'
#define ll long long int
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
const int N = 20;
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int n, m;
int si, sj, di, dj;
bool valid(int i, int j)
{
    if (i <= 0 || i > n || j <= 0 || j > m) // 1-based
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
            if(valid(ci, cj) && vis[ci][cj] && ci == di && cj == dj) break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    n = 8, m = 8;

    int tt; cin >> tt;
    while (tt--)
    {
        string x, y; cin >> x >> y;

        if(x.front() == 'a') si = 1;
        if(x.front() == 'b') si = 2;
        if(x.front() == 'c') si = 3;
        if(x.front() == 'd') si = 4;
        if(x.front() == 'e') si = 5;
        if(x.front() == 'f') si = 6;
        if(x.front() == 'g') si = 7;
        if(x.front() == 'h') si = 8;

        if(x.back() == '1') sj = 1;
        if(x.back() == '2') sj = 2;
        if(x.back() == '3') sj = 3;
        if(x.back() == '4') sj = 4;
        if(x.back() == '5') sj = 5;
        if(x.back() == '6') sj = 6;
        if(x.back() == '7') sj = 7;
        if(x.back() == '8') sj = 8;

        if(y.front() == 'a') di = 1;
        if(y.front() == 'b') di = 2;
        if(y.front() == 'c') di = 3;
        if(y.front() == 'd') di = 4;
        if(y.front() == 'e') di = 5;
        if(y.front() == 'f') di = 6;
        if(y.front() == 'g') di = 7;
        if(y.front() == 'h') di = 8;

        if(y.back() == '1') dj = 1;
        if(y.back() == '2') dj = 2;
        if(y.back() == '3') dj = 3;
        if(y.back() == '4') dj = 4;
        if(y.back() == '5') dj = 5;
        if(y.back() == '6') dj = 6;
        if(y.back() == '7') dj = 7;
        if(y.back() == '8') dj = 8;

        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        // if(!vis[di][dj]) cout << -1 << "\n";
        // else cout << dis[di][dj] << "\n";

        cout << dis[di][dj] << nl;
        // cout << "To get from " << x << " to " << y << " takes " << dis[di][dj] << " knight moves." << nl;
    }

    return 0;
}
// https://www.spoj.com/problems/NAKANJ/