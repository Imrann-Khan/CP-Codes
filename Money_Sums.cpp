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
    int n;
    cin >> n;
    vector<int> coins(n+1);
    int total=0;
    for(int i=1;i<=n;i++)
    {
        cin>>coins[i];
        total+=coins[i];
    }
    vector<vector<bool>> dp(n+1, vector<bool> (total+1, false));
    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=total;j++)
        {
            if((j-coins[i]>=0 and dp[i-1][j-coins[i]]) or dp[i-1][j]) dp[i][j]=true;
        }
    }
    vector<int> ans;

    for(int i=1;i<=total;i++)
    {
        if(dp[n][i]) ans.push_back(i);
    }

    cout<<ans.size()<<endl;
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
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