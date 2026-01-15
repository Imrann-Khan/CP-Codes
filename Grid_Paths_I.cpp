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
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]=='.') dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>0 and grid[i][j-1]=='.' and grid[i][j]=='.')
            {
                dp[i][j]+=(dp[i][j-1] % MOD);
            }
            if(i>0 and grid[i-1][j]=='.' and grid[i][j]=='.')
            {
                dp[i][j]+=(dp[i-1][j] % MOD);
            }
        }
    }
    cout<<dp[n-1][n-1] % MOD<<endl;
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
