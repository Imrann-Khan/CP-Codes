#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;


vector<ll> chk(ll n)
{
    vector<ll> v;
    while(n>0)
    {
        v.push_back(n%10);
        n/=10;
    }
    vector<ll> temp=v;
    sort(temp.begin(),temp.end(),greater<ll>());
    if(temp==v) return temp;
    else
    {
        v.empty();
        return v;
    }
}

signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll> a(n);
        vector<ll> s;
        bool f=false;
        ll p=0;
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++)
        {
            ll x=a[i];
            if(x>=10 and x%10>=x/10 and x/10>=p)
            {
                p=x%10;
            }
            else
            {
                if(x<p)
                {
                    f=true;
                    break;
                }
                p=x;
            }
        }
        
        if(!f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}