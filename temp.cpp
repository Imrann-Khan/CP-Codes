#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    unordered_set<int> s;
    if(abs(a-b)>6)
    {
        for(ll i=min(a,b);i>0;i--)
        {
            s.insert(i);
        }
        for(ll i=max(a,b);i<=12;i++)
        {
            s.insert(i);
        }
    }
    else
    {
        for(ll i=min(a,b);i<=max(a,b);i++)
        {
            s.insert(i);
        }
    }
    if(s.find(c)!=s.end() && s.find(d)!=s.end())
    {
        if(c==a or c==b or d==a or d==b) cout<<"YES\n";
        else cout<<"NO\n";
    }
    else if(s.find(c)!=s.end() || s.find(d)!=s.end()) cout<<"YES\n";
    else cout<<"NO\n";
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