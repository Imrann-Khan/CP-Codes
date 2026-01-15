#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


void solve()
{
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    ll ans=INT_MAX;
    ll mx=INT_MIN;
    for(ll i=1;i<n;i++)
    {
        mx=max(v[i-1],v[i]);
        ans=min(ans,mx);
    }
    cout<<ans-1<<endl;
}

signed main()
{
    fast
    ll t; cin>>t;
    ll z=t;
    while(t--)
    {
        //cout<<"Case "<<z-t<<": \n";
        solve();
    }
    
}