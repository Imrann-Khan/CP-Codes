#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


void solve()
{
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll temp;
    bool x=false;
    for(ll i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            temp=i;
            x=true;
            break;
        }
    }
    if(!x)
    {
        cout<<"Yes\n";
        return;
    }
    x=false;
    for(ll i=temp+1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            x=true;
            break;
        }
    }
    if(a[n-1]>a[0] || x) cout<<"No\n";
    else cout<<"Yes\n";
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