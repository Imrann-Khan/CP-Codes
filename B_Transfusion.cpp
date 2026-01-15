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
    ll a[n];
    rep(i, 0, n - 1) cin >> a[i];
    ll x = 0, y = 0;
    rep(i, 0, n - 1)
    {
        if (i % 2 == 0)
            x += a[i];
        else
            y += a[i];
    }
    ll unique = (x + y) / n;
    if ((x + y) % n != 0)
    {
        cout << "NO\n";
        return;
    }
    ll rx = unique * ((n + 1) / 2);
    ll ry = unique * (n / 2);
    if (x == rx and y == ry)
        cout << "YES\n";
    else
        cout << "NO\n";
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
