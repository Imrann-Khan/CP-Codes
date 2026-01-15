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
    string s;
    cin >> s;
    vector<char> d(s.size());
    // rep(i, 0, s.size() - 1) d[i] = s[i];
    rep(i, 1, d.size() - 1)
    {
        while (i >= 1 and s[i] > s[i - 1] + 1 and s[i] > '0')
        {
            char tmp = s[i];
            s[i] = s[i - 1];
            s[i - 1] = tmp - 1;
            if (i > 1)
                i--;
            else
                break;
        }
    }
    cout << s << endl;
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
