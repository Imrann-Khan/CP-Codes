#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

ll lcm(ll a, ll b)
{
    __gcd(a, b);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> s;
    bool g = false;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
        if (a[i] == 1)
            g = true;
    }
    if (g)
    {
        cout << "Yes\n";
        return;
    }
    auto it = s.begin();
    ll x = *it++;
    ll y;
    ll cnt = 0;
    for (auto k = it; k != s.end(); k++)
    {
        if (*k % x != 0)
        {
            y = *k;
            break;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (a[i] % x == 0 or a[i] % y == 0)
            cnt++;
    }
    if (cnt == n)
        cout << "Yes\n";
    else
        cout << "No\n";
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