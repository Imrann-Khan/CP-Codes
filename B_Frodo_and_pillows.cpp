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

bool chk(ll n, ll m, ll k, ll mid)
{
    // if (mid <= n)
    //     return false;
    ll r = n - k + 1;
    ll sum = 0;
    if (mid == r)
    {
        sum = (r * (r + 1)) / 2;
    }
    else if (mid < r)
    {
        ll h = r - mid;
        sum = (mid * (mid + 1) / 2) + h;
    }
    else
    {
        sum = (r * (r + 1)) / 2;
        sum += (mid - r) * r;
    }
    ll l = k - 1;
    if (mid - 1 == l)
    {
        sum += (l * (l + 1)) / 2;
    }
    else if (mid - 1 > l)
    {
        sum += (mid * (mid - 1) / 2);
        l = mid - l - 1;
        sum -= (l * (l + 1) / 2);
    }
    else
    {
        ll h = l - mid + 1;
        sum += (mid * (mid - 1) / 2) + h;
    }
    // cout << sum << endl;
    if (sum <= m)
        return true;
    else
        return false;
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1, r = 2e9 + 2;
    while (r >= l)
    {
        ll mid = (r + l) >> 1;
        if (chk(n, m, k, mid))
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << l - 1 << endl;
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
