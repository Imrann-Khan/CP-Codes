#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;



void solve()
{
    ll n,m;
    cin>>n>>m;
    if(n<m) cout<<"No\n";
    else
    {
        ll temp=n-m;
        if(temp%2==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
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