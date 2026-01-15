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
const int N = 1e7 + 1;

void solve()
{
    int n, ans=0;
    cin>>n;
    vector<int> p(n), wt(n);
    rep(i,0,n-1){
        cin>>p[i]>>wt[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (31, 0));
    for(int i=0;i<=n;i++){
        for(int sum=0;sum<=30;sum++){
            if(i==0 or sum==0){
                dp[i][sum]=0;
                continue;
            }
            dp[i][sum]=dp[i-1][sum];
            if(wt[i-1]<=sum){
                dp[i][sum]=max(dp[i][sum], dp[i-1][sum-wt[i-1]]+p[i-1]);
            }
        }
    }
    int g;
    cin>>g;
    while(g--){
        int c;
        cin>>c;
        ans+=dp[n][c];
    }
    cout<<ans<<endl;
}

signed main()
{
    fast
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
