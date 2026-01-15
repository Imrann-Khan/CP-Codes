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
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll cur = 0;
    ll p = 1, dec = 1;
    int st = s.size() - 1;
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        ll new_cur = cur + (s[i] - '0') * dec;
        if (dec < n)
            dec *= 10;
        if (new_cur >= n)
        {
            ans += cur * p;
            p *= n;
            i = st--;
            cur = 0;
            dec = 1;
        }
        else
        {
            cur = new_cur;
            if (s[i] != '0')
                st = i;
        }
    }
    ans += cur * p;
    cout << ans << endl;
}

signed main()
{
    fast
        ll t;
    t = 1;
    while (t--)
    {
        solve();
    }
}
