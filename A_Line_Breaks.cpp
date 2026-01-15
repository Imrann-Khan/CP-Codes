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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n - 1) cin >> s[i];
    int t = 0;
    int cnt = 0;
    rep(i, 0, n - 1)
    {
        if (t + s[i].length() <= m)
        {
            t += s[i].length();
            cnt++;
        }
        else
            break;
    }
    cout << cnt << endl;
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
