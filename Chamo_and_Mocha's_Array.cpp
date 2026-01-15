#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;



void solve()
{
    ll n; cin>>n;
    vector<ll> a(n);
    ll temp=INT_MAX;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(i!=n-1)
        {
            if(a[i]<temp) temp=a[i];
        }
    }
    for(ll i=1;i<n;i++)
    {
        if(a[i]<a[i-1]) 
        {
            if(temp>a[i-1]) temp=a[i];
        }
        else 
        {
            if(temp<a[i-1]) temp=a[i-1];
        }
    }
    cout<<temp<<endl;
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