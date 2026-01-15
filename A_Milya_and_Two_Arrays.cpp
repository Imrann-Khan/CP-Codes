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
    ll a[n];
    ll b[n];
    set<ll> s1;
    set<ll> s2;
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        s1.insert(a[i]);
    }
    rep(i, 0, n - 1)
    {
        cin >> b[i];
        s2.insert(b[i]);
    }
    if (s1.size() + s2.size() > 3)
        cout << "Yes\n";
    else
        cout << "No\n";
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
