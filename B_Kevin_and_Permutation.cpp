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
    ll ans[n + 1] = {0};
    int j = 1;
    for (int i = k; i <= n; i += k)
    {
        ans[i] = j;
        j++;
    }
    rep(i, 1, n)
    {
        if (ans[i] == 0)
            ans[i] = j++;
    }
    rep(i, 1, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
