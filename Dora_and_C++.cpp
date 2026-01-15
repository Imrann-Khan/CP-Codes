#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll p = __gcd(a, b);
    for (ll i = 0; i < n; i++)
        v[i] %= p;
    sort(v.begin(), v.end());
    ll ans = v[n - 1] - v[0];
    for (ll i = 1; i < n; i++)
        ans = min(ans, v[i - 1] - v[i] + p);
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