#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


void solve()
{
    ll l,r,k;
    cin >>l>>r>>k;
    if(l==r && l==1) cout<<"NO\n";
    else if(l==r)   cout<<"YES\n";
    else 
    {
        ll x;
        if(l%2==1 and r%2==1)  x=(r-l+2)/2;   
        else    x=(r-l+1)/2;
        if(x<=k) cout<<"YES\n";
        else    cout<<"NO\n";
    }
}

signed main()
{
    ll t; cin>>t;
    //ll z=t;
    while(t--)
    {
        //cout<<"Case "<<z-t<<": ";
        solve();
    }
}