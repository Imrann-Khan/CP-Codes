#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;



signed main()
{
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    vector<ll> pre(n+1);
    vector<ll> suf(n+1);
    pre[0]=v[0];
    for(ll i=1;i<n;i++) pre[i]=__gcd(pre[i-1],v[i]);
    suf[n-1]=v[n-1];
    for(ll i=n-2;i>=0;i--) suf[i]=__gcd(suf[i+1],v[i]);
    ll ans=max(suf[1],pre[n-2]);
    for(ll i=1;i<n-1;i++)
    {
        ans=max(ans,__gcd(pre[i-1],suf[i+1]));
    }
    cout<<ans<<endl;
    return 0;
}