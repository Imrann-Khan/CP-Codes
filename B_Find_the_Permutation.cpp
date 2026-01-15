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
    ll n;
    cin >> n;
    vector<string> g(n);
    rep(i, 0, n - 1) cin >> g[i];
    vector<ll> p(n);
    rep(i, 0, n - 1) p[i] = i;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool x = 0;
            if (p[i] < p[j])
            {
                if (g[p[i]][p[j]] != '1')
                    x = 1;
            }
            else
            {
                if ((g[p[j]][p[i]] != '0'))
                    x = 1;
            }
            if (x)
            {
                swap(p[i], p[j]);
            }
        }
    }
    rep(i, 0, n - 1)
    {
        cout << p[i] + 1 << " \n"[i == n - 1];
    }
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
