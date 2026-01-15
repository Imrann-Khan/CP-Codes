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
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    rep(i, 1, n) cin >> a[i];
    if (n == k)
    {
        bool f = 1;
        ll ans;
        for (int i = 2; i <= n; i += 2)
        {
            if (i / 2 != a[i])
            {
                ans = i / 2;
                f = 0;
                break;
            }
        }
        if (!f)
            cout << ans << endl;
        else
            cout << n / 2 + 1 << endl;
    }
    else
    {
        bool f = 0;
        for (int i = 2; i <= n - k + 2; i++)
        {
            if (a[i] != 1)
            {
                f = 1;
                break;
            }
        }
        if (f)
            cout << 1 << endl;
        else
        {
            ll ans = 2;
            for (int i = n - k + 1; i <= n; i += 2)
            {
                if (a[i] != ans)
                {
                    cout << ans << endl;
                    return;
                }
            }
        }
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
