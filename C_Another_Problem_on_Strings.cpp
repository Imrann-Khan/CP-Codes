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
    int k;
    string s;
    cin >> k >> s;
    int n = (int)s.size();
    int prfx[n + 1];
    prfx[0] = 0;
    ll ans = 0;
    rep(i, 1, n)
    {
        prfx[i] = (s[i - 1] == '1') + prfx[i - 1];
    }
    rep(i, 1, n)
    {
        if (prfx[n] - prfx[i - 1] < k)
            break;
        int p = n, q = n + 1;
        int l = i, r = n;
        while (r >= l)
        {
            int mid = (l + r) >> 1;
            if (prfx[mid] - prfx[i - 1] >= k)
            {
                p = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        l = i;
        r = n;
        while (r >= l)
        {
            int mid = (l + r) >> 1;
            if (prfx[mid] - prfx[i - 1] > k)
            {
                q = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        // cout << i << " " << p << " " << q << endl;
        ans += (q - p);
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
