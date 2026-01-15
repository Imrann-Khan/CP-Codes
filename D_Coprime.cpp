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
    int f[n + 1];
    int indx[1001] = {0};
    vector<int> v;
    int mx = 0;
    rep(i, 1, n)
    {
        int x;
        cin >> x;
        mx = max(mx, x);
        indx[x] = i;
    }
    int ans = -1;
    rep(i, 1, mx)
    {
        if (indx[i] != 0)
        {
            rep(j, i, mx)
            {
                if (indx[j] != 0 and __gcd(i, j) == 1)
                {
                    ans = max(ans, indx[i] + indx[j]);
                }
            }
        }
    }
    cout << ans << endl;
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
