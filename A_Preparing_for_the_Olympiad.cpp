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
    cin >> n;
    pair<int, int> p[n];
    rep(i, 0, n - 1)
    {
        cin >> p[i].first;
    }
    rep(i, 0, n - 1)
    {
        cin >> p[i].second;
    }
    int x = 0, y = 0;
    rep(i, 1, n - 1)
    {
        if (x + (p[i - 1].first - p[i].second) > x)
        {
            x += (p[i - 1].first - p[i].second);
        }
    }
    x += p[n - 1].first;
    cout << x << endl;
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
