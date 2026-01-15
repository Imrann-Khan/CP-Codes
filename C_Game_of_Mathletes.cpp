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
    int n, k;
    cin >> n >> k;
    ll a[n];
    ll m[2 * n + 1];
    rep(i, 0, 2 * n)
    {
        m[i] = 0;
    }
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    ll ans = 0;
    rep(i, 1, min(n, k))
    {
        ans += min(m[i], m[k - i]);
    }
    cout << ans / 2 << endl;
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
