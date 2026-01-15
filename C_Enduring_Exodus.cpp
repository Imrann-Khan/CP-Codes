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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> prfx(n);
    prfx[0] = (s[0] - '0') == 0;
    rep(i, 1, n - 1)
        prfx[i] = ((s[i] - '0') == 0) + prfx[i - 1];
    int l = 1;
    int r = n;
    int ans = -1;
    while (r >= l)
    {
        int mid = (l + r) >> 1;
        bool flag = 0;
        rep(i, 0, n - 1)
        {
            if (s[i] == '0')
            {
                int lt = max(i - mid, 0);
                int rt = min(i + mid, n - 1);
                int len = prfx[rt] - prfx[lt];
                if (s[lt] == '0')
                    len++;
                if (len >= (k + 1))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
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
