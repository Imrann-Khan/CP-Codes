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

vector<vector<int>> dp(1001, vector<int>(3001,-1));

int solve(int i, int rem, int n, vector<int> &load, vector<int> &maxLoad){
    if(i==n) return 0;

    if(dp[i][rem]!=-1) return dp[i][rem];

    int notTaken = solve(i+1, rem, n, load, maxLoad);
    int taken = 0;

    if(rem>=load[i]){
        taken = 1 + solve(i+1, min(rem-load[i], maxLoad[i]), n, load, maxLoad);
    }

    return dp[i][rem] = max(taken, notTaken);
}

signed main()
{
    fast
    int n;
    while (cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<1001;i++)
            for(int j=0;j<3001;j++)
                dp[i][j]=-1;
        
        vector<int> load(n), maxLoad(n);
        rep(i,0,n-1) 
            cin>>load[i]>>maxLoad[i];
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, 1 + solve(i+1, maxLoad[i], n, load, maxLoad));
        }
        cout<<ans<<endl;
    }
}
