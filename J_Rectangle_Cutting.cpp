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
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
    for (int i = 1; i <= a; i++) dp[i][1] = i - 1;
    for (int j = 1; j <= b; j++) dp[1][j] = j - 1;
    for (int i = 2; i <= a; i++)
    {
        for (int j = 2; j <= b; j++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                int best = INT_MAX;
                for (int k = 1; k < i; k++)
                {
                    best = min(best, dp[k][j] + dp[i-k][j] + 1);
                }
                for (int k = 1; k < j; k++)
                {
                    best = min(best, dp[i][k] + dp[i][j-k] + 1);
                }
                dp[i][j] = best;
            }
        }
    }

    cout << dp[a][b] << endl;
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