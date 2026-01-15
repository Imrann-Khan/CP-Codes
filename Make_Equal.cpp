#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll arr[n];
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        ll temp=0;
        ll avg=ceil(sum/n);
        bool x=false;
        for(ll i=0;i<n;i++)
        {
            if(arr[i]+temp<avg) 
            {
                x=true;
                break;
            }
            else 
            {
                temp=arr[i]+temp-avg;
            }
        }
        if(x) cout<<"NO\n";
        else cout<<"YES\n";
    }
}