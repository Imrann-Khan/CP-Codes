#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;



ll fn(ll n)
{
    if(n==0) return (n | (n+1));
    else return ((n-1) | (n+1) | n);
}

void solve()
{
    ll n,m,a;
    cin>>n>>m;
    a=fn(n);
    ll t=n+1;
    ll b=fn(t);
    ll x=ceil(log2(n));
    ll y=pow(2,x);
    if(m==0)
    {
        cout<<n<<endl;
        return;
    }
    if(m-1<(y-n))
    {
        cout<<a<<endl;
        return;
    }
    else
    {
        m-=(y-n+1);
        a=ceil(pow(2,x+1))-1;
        ll z=ceil(log2(a));
        while(m>z)
        {
            m-=z;
            z=pow(2,z+2)-pow(2,z+1);
            a=pow(2,z+1)-1;
        }
        cout<<a<<endl;
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