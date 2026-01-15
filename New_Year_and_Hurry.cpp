#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

signed main()
{
    fast
    ll rem=240;
    ll n,k;
    cin>>n>>k;
    rem-=k;
    ll cnt=0;
    for(ll i=1;i<=n;i++)
    {
        ll temp=5*i;
        if(temp<=rem)
        {
            rem-=temp;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}