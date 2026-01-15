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
    int n, m, k;
    cin >> n >> m >> k;
    int a[m];
    bool fr[n + 1] = {0};
    rep(i, 0, m - 1)
    {
        cin >> a[i];
    }
    rep(i, 0, k - 1)
    {
        int x;
        cin >> x;
        fr[x] = 1;
    }
    set<int> s;
    rep(i, 1, n)
    {
        if (fr[i] == 0)
        {
            s.insert(i);
        }
    }

    rep(i, 0, m - 1)
    {
        if (s.empty())
        {
            cout << 1;
            continue;
        }
        if (s.find(a[i]) == s.end())
        {
            cout << 0;
        }
        else
        {
            s.erase(a[i]);
            if (s.empty())
            {
                cout << 1;
            }
            else
                cout << 0;
            s.insert(a[i]);
        }
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
