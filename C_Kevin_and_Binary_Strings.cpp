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
    int l = 1;
    int cnt1 = 0;
    rep(i, 0, s.size() - 1)
    {
        if (s[i] == '1')
            cnt1++;
    }
    if (s.size() == cnt1)
    {
        cout << 1 << " " << s.size() << " " << 1 << " " << 1 << endl;
        return;
    }
    bool f = 0;
    int cnt = 0;
    int idx;
    rep(i, 0, s.size() - 1)
    {
        if (s[i] == '0' and !f)
        {
            cnt++;
            f = 1;
            idx = i + 1;
        }
        else if (s[i] == '0' and f)
            cnt++;
        else if (s[i] == '1' and !f)
            continue;
        else
        {
            break;
        }
    }
    // cout << idx << " " << cnt << endl;
    l = idx - min(cnt, idx - 1);
    cout << 1 << " " << s.size() << " " << l << " " << s.size() - min(cnt, idx - 1) << " " << endl;
    // else
    //     cout << 1 << " " << s.size() << " " << l - cnt2 - 1 << " " << s.size() - l << " " << endl;
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
