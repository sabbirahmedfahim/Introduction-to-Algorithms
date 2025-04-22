#include <bits/stdc++.h>
#define nl '\n'
#define ll long long int
#define all(c) c.begin(),c.end()
#define print(c) for(auto e : c) cout << e << " "; cout << nl
using namespace std;
int lcs(string a, int n, string b, int m)
{
    if(n == 0 || m == 0) return 0;
    
    if(a[n-1] == b[n-1])
    {
        int ans = lcs(a, n-1, b, m-1);
        return ans+1;
    }
    else
    {
        int ans1 = lcs(a, n-1, b, m);
        int ans2 = lcs(a, n, b, m-1);
        return max(ans1, ans2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string a = "sabbir", b = "jabir";
    int n = a.size(), m = b.size();

    cout << lcs(a, n, b, m) << nl;

    return 0;
}