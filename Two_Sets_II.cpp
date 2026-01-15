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

const int mod = 1e9+7;

void solve()
{
    int n;
    cin >> n;
    ll sum = n*(n+1)/2;
    if(sum&1)
    {
        cout<<0<<endl;
        return;
    }

    sum/=2;
    vector<vector<int>> dp(sum+1,vector<int> (n,0));

    dp[0][0]=1;

    for(int i=1;i<n;i++)
    {
        for(int x=0;x<=sum;x++)
        {
            dp[x][i]=dp[x][i-1]%mod;
            if(x-i>=0) dp[x][i]+=dp[x-i][i-1]%mod;
        }
    }
    cout<<dp[sum][n-1]%mod<<endl;
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