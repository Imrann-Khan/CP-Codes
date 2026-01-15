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
    vector<int> a(n);
    vector<int> b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    int l = 0, r = 10000;
    while (r >= l)
    {
        int mid = (r + l) >> 1;
        bool flag = 0;
        int rem = k;
        rep(i, 0, n - 1)
        {
            if (mid * a[i] > b[i])
            {
                int tmp = mid * a[i] - b[i];
                if (rem >= tmp)
                    rem -= tmp;
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << l - 1 << endl;
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
