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
    ll l, r;
    cin >> l >> r;
    if (r < 2 * l)
        cout << -1 << " " << -1 << endl;
    else
        cout << l << " " << 2 * l << endl;
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
