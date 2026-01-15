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

int calculateSubsetSum(int n, vector<int> &a, int sum){
    sum/=2;
    vector<bool> dp(sum+1, false);
    dp[0]=true;
    int res=0;

    for(int i=0;i<n;i++){
        for(int j=sum;j>=a[i];j--){
            if(dp[j-a[i]]){
                dp[j]=true;
                res=max(res, j);
            }
        }
    }
    return res;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int ans=0;
    rep(i,0,n-1){
        cin>>a[i];
        ans+=a[i];
    }
    cout<<ans - 2*calculateSubsetSum(n,a,ans)<<endl;
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
