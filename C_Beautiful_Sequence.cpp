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

const int MAXN = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    vector<int> dp(4, 0);
    dp[0] = 1;
    rep(i, 0, n - 1)
    {
        int x;
        cin >> x;
        if (x == 2)
            dp[x] = (dp[x] + dp[x]) % 998244353;
        dp[x] = (dp[x] + dp[x - 1]) % 998244353;
    }
    cout << dp[3] << endl;
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
