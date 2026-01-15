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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    string s;
    cin >> s;
    int cns = 0;
    int ans = 0;
    rep(i, 0, n - 1)
    {
        // cout << cns << " ";
        if (s[i] == '1')
        {
            int temp;
            if (cns >= m)
            {
                int res = cns / (m + k - 1);
                ans += cns / (m + k - 1);
                if (cns - (res * (m + k - 1)) == 0)
                {
                    i += k - 1;
                }
                else
                {
                    int f = cns - (res * (m + k - 1));
                    if (f >= m)
                    {
                        ans++;
                        i += f + m + k - 1;
                    }
                }
            }
            cns = 0;
        }
        else
            cns++;
    }
    if (cns)
    {
        int temp;
        if (cns >= m)
        {
            int res = cns / (m + k - 1);
            ans += cns / (m + k - 1);
            if (cns - (res * (m + k - 1)) >= m)
                ans++;
        }
        cns = 0;
    }
    cout << ans << endl;
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
