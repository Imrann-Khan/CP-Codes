#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

bool isPower(ll x, ll y)
{
    float res1 = log(y) / log(x);
    return res1==floor(res1);
}


bool Onlyab(ll x,ll y,ll z)
{
    if(isPower(y,x)) return true;
    if(isPower(z,x)) return true;
    if(x%(y*z)==0) Onlyab(x/(y*z),y,z);
    return false;
}


signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        ll a,b,l,ans=0;
        cin>>a>>b>>l;
        ll x=0,y=0,z=0;
        ll k=1;
        ll f=l;
        set<ll> v;
        for(ll i=1;i<=(l/2);i++)
        {
            if(l%i==0)
            {
                v.insert(i);
                v.insert(l/i);
            }
        }
        //for(auto i=v.begin();i!=v.end();i++) cout<<*i<<" ";
        for(auto k=v.begin();k!=v.end();k++) 
        {
            f=l/(*k);
            if(isPower(a,f)) ans++;
            else if(isPower(b,f)) ans++;
            else if(Onlyab(f,a,b)) ans++;  
            //else cout<<*k<<"f "; 
        }
        cout<<ans<<endl;
    }
}