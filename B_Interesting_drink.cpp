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
    vector<ll> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    sort(a.begin(), a.end());
    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        cout << upper_bound(a.begin(), a.end(), x) - a.begin() << endl;
    }
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
