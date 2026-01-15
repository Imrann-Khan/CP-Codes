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

int dp[101][10201];


signed main()
{
    fast
    int n, m;
    while(cin>>n>>m){
        int limit = n + 200;
        memset(dp, -1, sizeof(dp)); 
        rep(i,0,m) dp[i][0] = 0;
        
        vector<int> fav(m), price(m);
        rep(i,0,m-1){
            cin>>price[i]>>fav[i];
        }

        for(int i=1;i<=m;i++){
            for(int p=1;p<=limit;p++){
                dp[i][p]=dp[i-1][p];
                if(p>=price[i-1] && dp[i-1][p-price[i-1]]!=-1){
                    if(dp[i][p]==-1) dp[i][p]=0;
                    dp[i][p]=max(dp[i][p], dp[i-1][p-price[i-1]]+fav[i-1]);
                }
            }
        }

        int ans = 0;
        for(int p=0;p<=n;p++){
            if(dp[m][p]!=-1) ans = max(ans, dp[m][p]);
        }

        for(int p=2001;p<=limit;p++){
            if(dp[m][p]!=-1) ans = max(ans, dp[m][p]);
        }
        cout<<ans<<endl;
    }
}


