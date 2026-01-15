#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;
    k--;
    ll l = 1, r = n;
    // ll mid = (l + r) / 2;
    // ll left = ((mid + 1) * mid) / 2 + (mid)*k;
    // ll cnt = n - mid;
    // ll right = (cnt * (cnt + 1)) / 2 + cnt * (mid) + cnt * k;
    ll ans = 1e18;
    // l = mid;
    // cout << ans << endl;
    ll mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll left = ((mid + 1) * mid) / 2 + (mid)*k;
        ll cnt = n - mid;
        ll right = (cnt * (cnt + 1)) / 2 + cnt * (mid) + cnt * k;
        ans = min(ans, abs(left - right));
        if (left >= right)
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
        // cout << ans << endl;
    }
    mid--;
    ll left = ((mid + 1) * mid) / 2 + (mid)*k;
    ll cnt = n - mid;
    ll right = (cnt * (cnt + 1)) / 2 + cnt * (mid) + cnt * k;
    ans = min(ans, abs(left - right));
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