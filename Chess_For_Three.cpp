#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;



void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    
        ll s=0;
        vector<ll> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end(),greater<ll>());
        while(v[2]!=0 || v[1]!=0)
        {
            v[0]--;
            v[1]--;
            s++;
            sort(v.begin(),v.end(),greater<ll>());
        }
        if(v[0]%2==0) cout<<s<<endl;
        else cout<<-1<<endl;
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