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
    int a, b;
    cin >> a >> b;
    set<int> s;
    int ans = 0;
    ll tmp = a * b;
    for (int i = 1; i * i <= tmp; i++)
    {
        if (tmp % i == 0)
        {
            ll f = __gcd((int)tmp / i, i);
            if (f == a)
            {
                s.insert(tmp / i);
                s.insert(i);
            }
        }
    }
    cout << s.size() << endl;
}

signed main()
{
    fast
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
