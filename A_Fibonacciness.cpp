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
    ll a1, a2, a4, a5, a3;
    cin >> a1 >> a2 >> a4 >> a5;
    ll ans = 0;
    rep(i, -100, 100)
    {
        ll tmp = 0;
        if (i == a1 + a2)
            tmp++;
        if (a4 == i + a2)
            tmp++;
        if (a5 == i + a4)
            tmp++;
        ans = max(tmp, ans);
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
