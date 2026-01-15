#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void solve()
{
    ll n; cin>>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    ll ans=3;
    for(ll i=1;i<=n;i++) 
    {
        if(a[a[i]]==i) ans=2;
    }
    cout<<ans<<endl;
}

signed main()
{
    ll t;cin>>t;
    while(t--)
    {
        solve();
    }
}