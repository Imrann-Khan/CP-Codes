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
    ll x, y, a;
    cin >> x >> y >> a;
    bool f = 1;
    ll tmp = 0;
    a++;
    ll tx = a / (x + y);
    a = a - tx * (x + y);
    while (tmp < a)
    {
        if (f)
        {
            tmp += x;
            f = 0;
        }
        else
        {
            tmp += y;
            f = 1;
        }
    }
    if (f)
        cout << "YES\n";
    else
        cout << "NO\n";
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
