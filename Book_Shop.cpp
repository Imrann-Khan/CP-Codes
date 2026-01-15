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

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> bookP(n+1);
    vector<int> pages(n+1);
    for(int i = 1; i <= n; i++) cin >> bookP[i];
    for(int i = 1; i <= n; i++) cin >> pages[i];

    vector<int> dp(x+1, 0);
    for(int i=1;i<=n;i++)
    {
        for(int wt=x;wt>=bookP[i];wt--)
        {
            dp[wt]=max(dp[wt-bookP[i]]+pages[i],dp[wt]);
        }
    }
    cout << dp[x] << endl;
}

signed main()
{
    fast
        ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}