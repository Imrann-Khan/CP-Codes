#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;



void solve()
{
    ll x,y;
    cin>>x>>y;
    ll rem=0;
    ll count=0;
    if(y==0)
    {
        count=ceil(x/15.0);
        cout<<count<<endl;
        return;
    }
    else
    {
        if(y%2==0)
        {
            count=y/2;
            rem=count*7;
        }
        else 
        {
            count=y/2+1;
            rem=(y/2)*7+(y%2)*11;
        }
        if(x>rem)
        {
            x-=rem;
            ld z=ceil(x/15.0);
            count+=z;
        }
        cout<<count<<endl;
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