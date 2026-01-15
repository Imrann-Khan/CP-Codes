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
int dp[21][201][11];

int solve(vector<int> &a, int n, int m, int d)
{
    vector<vector<long long>> dp(m + 1, vector<long long>(d, 0));
    dp[0][0] = 1;
    for (int idx = 0; idx < n; idx++)
    {
        int rem = a[idx] % d;
        if (rem < 0)
            rem += d;
        for (int j = m - 1; j >= 0; j--)
        {
            for (int r = 0; r < d; r++)
            {
                if (dp[j][r] == 0)
                    continue;
                int nxt = (r + rem) % d;
                dp[j + 1][nxt] += dp[j][r];
            }
        }
    }
    return dp[m][0];
}

signed main()
{
    fast
    int n, q, tc = 1;
    while (cin >> n >> q, n || q)
    {
        cout << "SET " << tc++ << ":\n";
        vector<int> a(n);
        rep(i, 0, n - 1) cin >> a[i];

        for (int i = 1; i <= q; i++)
        {
            int d, m;
            cin >> d >> m;
            cout << "QUERY " << i << ": " << solve(a, n, m, d) << endl;
        }
    }
}
