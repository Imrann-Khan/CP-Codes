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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool f = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == 1 || a[i - 2] == 0)
        {
            ll d = min(a[i - 1], a[i]);
            a[i] -= d;
            a[i - 1] -= d;
        }
    }
    // rep(i, 0, n - 1) cout << a[i] << " ";
    // cout << endl;
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            f = 0;
    if (f)
        cout << "YES\n";
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
