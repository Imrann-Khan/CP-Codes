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
    string n;
    cin >> n;
    ll in_sum = 0;
    int c2 = 0, c3 = 0;
    for (char ch : n)
    {
        int d = ch - '0';
        in_sum += d;
        if (d == 2)
            c2++;
        if (d == 3)
            c3++;
    }
    bool p = 0;
    rep(b, 0, c3)
    {
        ll plus_needed = (9 - (in_sum % 9));
        ll tmp = (plus_needed - 6LL * b) % 9;
        if (tmp < 0)
            tmp += 9;
        ll req = (tmp * 5) % 9;
        if (req <= c2)
        {
            p = 1;
            break;
        }
    }
    if (p)
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
