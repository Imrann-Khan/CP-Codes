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

ll intPower(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    set<int> nb;
    map<int, int> fr;
    rep(i, 0, n - 1)
    {
        rep(j, 0, m - 1)
        {
            cin >> a[i][j];
            fr[a[i][j]]++;
        }
    }
    rep(i, 0, n - 1)
    {
        rep(j, 0, m - 1)
        {
            if (i + 1 < n and a[i][j] == a[i + 1][j])
                nb.insert(a[i][j]);
            else if (j + 1 < m and a[i][j] == a[i][j + 1])
                nb.insert(a[i][j]);
        }
    }
    if ((int)nb.size())
    {
        int tmp = 0;
        int cnt = 0;
        for (auto it : fr)
        {
            if (it.second > cnt and nb.find(it.first) != nb.end())
            {
                tmp = it.first;
                cnt = it.second;
            }
        }
        cout << fr.size() + nb.size() - 2 << endl;
    }
    else
        cout << fr.size() - 1 << endl;
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
