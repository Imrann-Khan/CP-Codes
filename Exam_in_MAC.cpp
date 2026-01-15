#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;


signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        ll ans=(c+2)*(c+1)/2;
        ll odd=0,even=0;
        for(ll i=0;i<n;i++)
        {
            ll a;
            cin>>a;
            if(a%2==0) even++;
            else odd++;
            ans-=(a/2)+1;
            ans-=(c-a+1);
        }
        ans+=even*(even+1)/2;
        ans+=odd*(odd+1)/2;
        cout<<ans<<endl;
    }
}