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
    ll n, m;
    cin >> n >> m;
    ll ans = m * n * 4;
    ll x = 0, y = 0;
    ll p, q;
    ll a = 0, b = 0;
    rep(i, 0, n - 1)
    {
        cin >> p >> q;
        a += p;
        b += q;
        if (i == 0)
        {
            x = a + m;
            y = b + m;
        }
        else
        {
            ans -= (x - a + y - b) * 2;
            x = a + m;
            y = b + m;
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
