#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void solve() {
    string s;
    cin>>s;
    bool f=false;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='i' and s[i+1]=='t')
        {
            f=true;
            break;
        }
    }
    if(f) cout<<"YES\n";
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