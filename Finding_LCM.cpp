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
    int a, b;
    ll l;
    cin >> a >> b >> l;
    ll tmp = lcm(a, b);
    if (l % tmp != 0)
        cout << "impossible\n";
    else
    {
        ll x = l / tmp;
        while (__gcd(tmp, x) != 1)
        {
            ll b = __gcd(tmp, x);
            x *= b;
            tmp /= b;
        }
        cout << x << endl;
    }
}

signed main()
{
    fast
        ll t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        cout << "Case " << c++ << ": ";
        solve();
    }
}
