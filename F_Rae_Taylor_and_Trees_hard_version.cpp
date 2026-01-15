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

ll intPower(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}


void solve()
{
    int n;
    cin>>n;
    vector<int> p(n), pre(n), suf(n+1);
    vector<pair<int, int>> ans;
    rep(i,0,n-1){
        cin>>p[i];
    }
    pre[0]=p[0];
    suf[n-1]=p[n-1];
    rep(i,1,n-1){
        pre[i]=min(pre[i-1], p[i]);
    }
    for(int i=n-2;i>=0;i--){
        suf[i] = max(suf[i+1], p[i]);
    }
    int last=pre[0];
    for(int i=0;i<n;i++){
        if(i==0){
            if(suf[i]!=p[i]) ans.push_back({suf[i], p[i]});
            continue;
        }
        if(pre[i-1]>suf[i]){
            cout<<"No\n";
            return;
        }
        if(suf[i]==suf[i-1]){
            if(suf[i]!=p[i]) ans.push_back({suf[i], p[i]});
        }
        else if(suf[i]<suf[i-1]){
            if(last!=-1) ans.push_back({suf[i], pre[i-1]});
            if(suf[i]!=p[i]) ans.push_back({suf[i], p[i]});
            last=pre[i];
        }
    }
    cout<<"Yes\n";
    for(int i=0;i<n-1;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}

signed main()
{
    fast

        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
