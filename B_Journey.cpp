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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 0;
    ll cnt = (n / (a + b + c));
    ans = cnt * 3;
    n -= (a + b + c) * cnt;
    // cout << n << endl;
    if (n > 0)
    {
        n -= a;
        ans++;
    }
    if (n > 0)
    {
        n -= b;
        ans++;
    }
    if (n > 0)
    {
        ans++;
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
