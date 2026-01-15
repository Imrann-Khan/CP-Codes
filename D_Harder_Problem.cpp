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
    vector<ll> a(n + 1);
    vector<ll> b(n + 1, 0);
    bool g[n + 1] = {0};
    rep(i, 1, n)
    {
        cin >> a[i];
    }
    rep(i, 1, n)
    {
        if (!g[a[i]])
        {
            b[i] = a[i];
            g[a[i]] = 1;
        }
    }
    int j = 1;
    rep(i, 1, n)
    {
        if (b[i] == 0)
        {
            while (j <= n and g[j])
                j++;
            b[i] = j;
            g[j] = 1;
        }
    }
    rep(i, 1, n) cout << b[i] << " ";
    cout << endl;
}

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
