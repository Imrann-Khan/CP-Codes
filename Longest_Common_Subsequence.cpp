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

void backTrack(vector<vector<int>> &dp, vector<int> &ans, int i, int j,vector<int> &a)
{
    if(i==0 or j==0) return;

    if(dp[i][j]==dp[i-1][j])
    {
        backTrack(dp,ans,i-1,j,a);
    }
    else if(dp[i][j]==dp[i][j-1])
    {
        backTrack(dp,ans,i,j-1,a);
    }
    else
    {
        ans.push_back(a[i-1]);
        backTrack(dp,ans,i-1,j-1,a);
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    vector<int> ans;
    backTrack(dp,ans,n,m,a);
    reverse(ans.begin(),ans.end());

    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<" ";
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