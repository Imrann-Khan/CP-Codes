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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i, 0, n - 1)
            cin >>
        a[i];
    rep(i, 0, m - 1)
            cin >>
        b[i];
    sort(b.begin(), b.end());
    ll last = LLONG_MIN;
    bool f = 1;
    rep(i, 0, n - 1)
    {
        ll tmp = LLONG_MAX;
        if (a[i] >= last)
            tmp = a[i];
        ll need = last + a[i];
        auto it = lower_bound(b.begin(), b.end(), need);
        // cout << *it << endl;
        if (it != b.end())
        {
            ll tmp2 = *it - a[i];
            // cout << tmp2 << endl;
            tmp = min(tmp, tmp2);
            a[i] = tmp;
        }
        if (tmp == LLONG_MAX)
        {
            f = 0;
            break;
        }
        last = tmp;
    }
    if (f)
    {
        cout << "YES\n";
        // rep(i, 0, n - 1)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
    }
    else
        cout << "NO\n";
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
