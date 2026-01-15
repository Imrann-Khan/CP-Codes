#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;



void solve()
{
    ll l,r;
    cin>>l>>r;
    ll x=floor(log2(r));
    ll y=pow(2,x);
    ll cnt=0;
    while(y>1)
    {
        y/=2;
        cnt++;
    }
    cout<<cnt<<endl;
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