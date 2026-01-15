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

ll lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    rep(i, 0, n - 1) cin >> a[i];
    // sort(a, a + n);
    ll ans = a[0];
    rep(i, 1, n - 1)
        ans = lcm(ans, a[i]);
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
