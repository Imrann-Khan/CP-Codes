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
const ll N = 2e3 + 5;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll p[n][m];
    ll ans[N], nxt[N];
    set<ll> a[N];
    bool mk[N];
    memset(nxt, -1, sizeof nxt);
    memset(mk, 0, sizeof mk);
    for (int i = 0; i < n; i++)
    {
        int x;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            a[i].insert(x);
        }
        nxt[*a[i].begin()] = i;
    }
    ll k = n * m;
    bool f = 1;
    for (int i = 0; i < k; i++)
        if (i < n)
        {
            if (nxt[i] == -1)
            {
                f = 0;
                break;
            }
            ans[i] = nxt[i];
            a[nxt[i]].erase(a[nxt[i]].begin());
            nxt[*a[nxt[i]].begin()] = nxt[i];
            if (mk[nxt[i]])
                f = 0;
            mk[nxt[i]] = 1;
        }
        else
        {
            if (nxt[i] == -1 || ans[i % n] != nxt[i])
            {
                f = 0;
                break;
            }
            a[nxt[i]].erase(a[nxt[i]].begin());
            nxt[*a[nxt[i]].begin()] = nxt[i];
        }
    if (f)
    {
        for (int i = 0; i < n; i++)
            cout << ++ans[i] << ' ';
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
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
