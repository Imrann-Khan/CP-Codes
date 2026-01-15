#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void solve()
{
    ll n; cin>>n;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    ll i=0,j=0;
    ll ans=0;
    ll p=n;
    while(i<n)
    {
        if(a[i]>b[j])
        {
            ans++;
            j++;
            n--;
        }
        else
        {
            i++;
            j++;
        }
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