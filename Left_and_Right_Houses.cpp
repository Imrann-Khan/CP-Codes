#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

using namespace std;

signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        //multiset<pair<ll,ll>> s;
        string s; cin>>s;
        ll zero=0,one=0;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='1') one++;
            else zero++;
        }
        ll remOne=one,remZero=zero;
        one=0; zero=0;
        ll temp=n, prev=1e9, ans;
        vector<ll> x;
        if(remOne>=remZero and zero>=one)
        {
            x.push_back(0);
        }
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                remOne--;
                one++;
            }
            else 
            {
                remZero--;
                zero++;
            }
            if(remOne>=remZero and zero>=one)
            {
                x.push_back(i+1);
            }
        }
        //for(ll i=0;i<x.size();i++) cout<<x[i]<<" ";
        for(ll i=0;i<x.size();i++)
        {
            if(abs(n-2*x[i])<prev)
            {
                ans=x[i];
                prev=abs(n-2*x[i]);
            }
        }
        cout<<ans<<endl;
    }
}