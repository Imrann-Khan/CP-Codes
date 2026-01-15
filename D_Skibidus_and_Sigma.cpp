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
    ll a[n][m];
    rep(i, 0, n - 1)
    {
        rep(j, 0, m - 1) cin >> a[i][j];
    }
    vector<pair<ll, ll>> v;
    rep(i, 0, n - 1)
    {
        ll tt = 0;
        rep(j, 0, m - 1)
        {
            tt += a[i][j];
        }
        v.push_back({tt, i});
    }
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
    ll ans = 0, sc = 0;
    // rep(i, 0, v.size() - 1)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    // cout << endl;
    rep(i, 0, v.size() - 1)
    {
        int tmp = v[i].second;
        rep(j, 0, m - 1)
        {
            sc += a[tmp][j];
            ans += sc;
        }
    }
    cout << ans << endl;
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
