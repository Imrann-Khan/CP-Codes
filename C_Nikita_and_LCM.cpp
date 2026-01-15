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
    sort(a, a + n);
    bool f = 1;
    rep(i, 0, n - 2)
    {
        if (a[n - 1] % a[i] != 0)
        {
            f = 0;
            break;
        }
    }
    if (!f)
        cout << n << endl;
    else
    {
        ll large = a[n - 1];
        set<ll> div;
        for (ll i = 1; i * i <= large; i++)
        {
            if (large % i == 0)
            {
                div.insert(i);
                div.insert(large / i);
            }
        }
        ll ans = 0;
        for (auto it : div)
        {
            ll curlcm = it;
            vector<ll> v;
            bool valid = true;
            rep(i, 0, n - 1)
            {
                if (curlcm == a[i])
                    valid = false;
                if (curlcm % a[i] == 0)
                    v.push_back(a[i]);
            }
            ll lcm = 1;
            for (auto i : v)
            {
                lcm = lcm * i / __gcd(i, lcm);
            }
            if (valid and lcm == curlcm)
                ans = max(ans, (ll)v.size());
        }
        cout << ans << endl;
    }
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
