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
    ll n;
    cin >> n;
    pair<ll, ll> p[n];
    rep(i, 0, n - 1)
    {
        cin >> p[i].first;
    }
    rep(i, 0, n - 1)
    {
        cin >> p[i].second;
    }
    if (n == 1)
    {
        cout << p[0].first + p[0].second << endl;
        return;
    }
    vector<pair<ll, ll>> a;
    vector<pair<ll, ll>> b;
    rep(i, 0, n - 1)
    {
        if (p[i].first < p[i].second)
            b.push_back({p[i].first, p[i].second});
        else
            a.push_back({p[i].first, p[i].second});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<pair<ll, ll>>());
    ll ans = 0;
    // rep(i, 0, a.size() - 1) cout << a[i].first << " ";
    // if (b.size())
    //     rep(i, 0, b.size() - 1) cout << b[i].first << " ";
    // cout << endl;
    // rep(i, 0, a.size() - 1) cout << a[i].second << " ";
    // if (b.size())
    //     rep(i, 0, b.size() - 1) cout << b[i].second << " ";
    // cout << endl;
    if (a.size() > 1)
    {
        rep(i, 1, a.size() - 1)
        {
            if ((a[i].first + a[i].second + a[i - 1].first) < (a[i - 1].first + a[i - 1].second + a[i].first))
            {
                ans += a[i].first;
                swap(a[i], a[i - 1]);
            }
            else
            {
                ans += a[i - 1].first;
            }
        }
    }
    if (b.size() == 0 and a.size() > 0)
        ans += a[a.size() - 1].first + a[a.size() - 1].second;
    else if (b.size() > 0 and a.size() > 0)
    {
        if (b[0].first > a[a.size() - 1].second)
            ans += b[0].first + b[0].second + a[a.size() - 1].first;
        else
            ans += b[0].second + a[a.size() - 1].first + a[a.size() - 1].second;
    }
    else
        ans += b[0].first + b[0].second;
    if (b.size() > 1)
        rep(i, 1, b.size() - 1) ans += b[i].second;
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
