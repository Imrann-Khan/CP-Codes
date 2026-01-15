#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;



void solve()
{
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(k+1,0);
    for(ll i=1;i<=k;i++) cin>>a[i];
    vector<ll> b(k+1,0);
    for(ll i=1;i<=k;i++) cin>>b[i];
    
    while(q--)
    {
        ll f; cin>>f;
        if(f==0) cout<<0<<" ";
        else
        {
            ll x=lower_bound(a.begin(),a.end(),f)-a.begin();
            ll s= b[x-1];
            ld m=0;
            if(x-1!=k)
            {
                ld y = (a[x]-a[x-1])/(b[x]-b[x-1]);
                ld u = a[x]-a[x-1];
                ld i = b[x]-b[x-1];
                y = u/i;
                m = (f-a[x-1])/y;
            }
            s+=m;
            cout<<s<<" ";
        }
    }
    cout<<endl;
}

signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}