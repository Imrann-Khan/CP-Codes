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
    ll ans = LLONG_MAX;
    int l = 1, r = k * ((n + k - 1) / k);
    while (r >= l)
    {
        int mid = (r + l) >> 1;
        ll temp = min(1LL * k * mid, LLONG_MAX);
        if (temp < n)
        {
            l = mid + 1;
            continue;
        }
        if (temp % n == 0)
            temp = temp / n;
        else
            temp = (temp / n) + 1;
        if (temp <= ans)
        {
            ans = temp;
            r = mid - 1;
        }
        else
            l = mid + 1;
        // cout << mid << " " << ans << endl;
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
