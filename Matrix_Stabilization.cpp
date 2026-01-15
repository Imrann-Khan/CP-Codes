#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;


void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++) cin>>a[i][j];
    }
    for(ll i=0;i<n;++i)
    {
        for(ll j=0;j<m;++j)
        {
            ll mx=0;
            if (i>0) mx=max(mx,a[i-1][j]);
            if (j>0) mx=max(mx,a[i][j-1]);
            if (i+1<n) mx=max(mx,a[i+1][j]);
            if (j+1<m) mx=max(mx,a[i][j+1]);
            a[i][j]=min(mx,a[i][j]);
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}


signed main()
{
    fast
    ll t;cin>>t;
    while(t--)
    {
        solve();
    }
}