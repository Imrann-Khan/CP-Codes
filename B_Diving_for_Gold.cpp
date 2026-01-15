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

void included_points(vector<vector<ll>> &dp, int w, vector<ll> &gold, vector<ll> &wt,  int W, int i, vector<pair<int,int>> &ans){
    if(i==0 || W==0) return;
    if(wt[i-1] <= W && dp[i][W] == dp[i-1][W-wt[i-1]] + gold[i-1]){
        ans.push_back({wt[i-1]/(3*w), gold[i-1]});
        included_points(dp, w, gold, wt, W-wt[i-1], i-1, ans);
    }
    else included_points(dp, w, gold, wt, W, i-1, ans);
}

int main()
{
    fast
    int maxTime, w;
    bool first = true;
    while (cin>>maxTime>>w)
    {
        int points;
        cin>>points;
        vector<ll> gold(points),wt(points);
        for(int i=0;i<points;i++){
            int d;
            cin>>d>>gold[i];
            wt[i] = 3*w*d;
        }

        vector<vector<ll>> dp(points+1, vector<ll> (maxTime+1, 0));

        for(ll i=0;i<=points;i++){
            for(int j=0;j<=maxTime;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                    continue;
                }
                if(wt[i-1] <= j){
                    dp[i][j] = max(dp[i-1][j-wt[i-1]] + gold[i-1], dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        if(!first) cout<<endl;
        first=0;

        cout<<dp[points][maxTime]<<endl;
        
        vector<pair<int,int>> ans;
        included_points(dp, w, gold, wt, maxTime, points, ans);
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }
}
