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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll s = 0;
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        s += a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i, 0, n - 1)
    {
        ll p = s - a[i];
        ll l = lower_bound(a.begin() + i + 1, a.end(), p - y) - a.begin();
        ll r = upper_bound(a.begin() + i + 1, a.end(), p - x) - a.begin();
        ans += abs(r - l);
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
    return 0;
}
