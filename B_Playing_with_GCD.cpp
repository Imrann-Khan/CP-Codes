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

ll lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

void solve()
{
    ll n;
    cin >> n;
    ll a[n + 2];
    rep(i, 1, n) cin >> a[i];
    a[0] = a[n + 1] = 1;
    ll b[n + 2];
    rep(i, 1, n + 1)
    {
        b[i] = lcm(a[i], a[i - 1]);
    }
    rep(i, 1, n)
    {
        if (__gcd(b[i], b[i + 1]) != a[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
