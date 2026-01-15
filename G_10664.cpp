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

void useDP(vector<int> &a)
{
    int n=a.size();
    int sum = accumulate(a.begin(), a.end(), 0);
    if(sum%2){
        cout<<"NO\n";
        return;
    }
    vector<vector<int>> dp(n+1, vector<int>(sum/2+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum/2;j++){
            if(i==0){
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=dp[i-1][j];
            if(j>=a[i-1]) 
                dp[i][j]=max(dp[i-1][j-a[i-1]]+a[i-1], dp[i][j]);
        }
    }
    if(dp[n][sum/2]==sum/2) cout<<"YES\n";
    else cout<<"NO\n";
}


void solve()
{
    vector<int> a;
    string line;
    getline(cin,line);
    stringstream ss(line);
    int x;
    while(ss>>x){
        a.push_back(x);
    }
    useDP(a);
    // int n = a.size();
    // for(int i=0;i<(1<<n);i++){
    //     int x=0,y=0;
    //     for(int j=0;j<n;j++){
    //         if(i & (1<<j))
    //             x+=a[j];
    //         else y+=a[j];
    //     }
    //     if(x==y){
    //         cout<<"YES\n";
    //         return;
    //     }
    // }
    // cout<<"NO\n";
}

signed main()
{
    fast
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--)
    {
        solve();
    }
}
