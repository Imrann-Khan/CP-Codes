#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (n == 2)
    {
        cout << abs(a[0] - a[1]) << endl;
        return;
    }
    ll c = abs(a[0] - a[n - 1]);
    for (ll i = 1; i < n / 2; i++)
    {
        c = __gcd(c, abs(a[i] - a[n - i - 1]));
    }
    cout << c << endl;
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