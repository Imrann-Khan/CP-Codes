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
    ll d;
    cin >> n >> d;
    ll a[n];
    rep(i, 0, n - 1) cin >> a[i];
    sort(a, a + n, greater<ll>());
    int rem = n;
    int ans = 0;
    rep(i, 0, n - 1)
    {
        int l = 1, r = n;
        int cnt = -1;
        ll tmp = a[i];
        while (r >= l)
        {
            int mid = (r + l) >> 1;
            if (mid * tmp > d)
            {
                cnt = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (cnt <= rem and cnt != -1)
        {
            ans++;
            rem -= cnt;
        }
        else
            break;
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
