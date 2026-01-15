#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


vector<ll> primefactor(ll n)
{
    vector<ll> v;
    v.push_back(1);
    ll cnt;
    for(ll i=2;i*i<=n;i++)
    {
        cnt=0;
        while(n%i==0)
        {
            cnt++;
            n/=i;
        }
        ll p=v.size();
        ll x=i;
        bool f=0;
        for(ll j=0;j<cnt;j++) 
        {
            if(f)
            {
                for(ll k=0;k<p;k++) v.push_back(x*v[k]);
                f=0;
            }
            else
            {
                for(ll k=p-1;k>=0;k--) v.push_back(x*v[k]);
                f=1;
            }
            x*=i;
        }
    }
    if(n>1)
    {
        for(ll k=v.size()-1;k>=0;k--)   v.push_back(n*v[k]);
    }
    //else v.push_back(f);
    return v;
}

void solve()
{
    ll n; cin>>n;
    vector<ll> v=primefactor(n);
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
}

signed main()
{
    fast
    ll t; cin>>t;
    ll z=t;
    while(t--)
    {
        cout<<"Case "<<z-t<<": \n";
        solve();
    }
    
}