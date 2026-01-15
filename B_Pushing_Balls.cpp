#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pi 3.141592653589793238462643383279502884197
using namespace std;

const ll MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    char a[n + 1][m + 1];
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            cin >> a[i][j];
        }
    }
    bool flag = 1;
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            if (a[i][j] == '1')
            {
                bool p = 1;
                bool q = 1;
                rep(k, 1, j)
                {
                    if (a[i][k] == '0')
                    {
                        p = 0;
                        break;
                    }
                }
                rep(k, 1, i)
                {
                    if (a[k][j] == '0')
                    {
                        q = 0;
                        break;
                    }
                }
                if (!p and !q)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

signed main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
