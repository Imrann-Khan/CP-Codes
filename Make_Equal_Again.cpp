#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;



signed main()
{
    fast
    ll t;cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll arr[n];
        ll left=0,right=n-1;
        set<ll> s;
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
            s.insert(arr[i]);
        }
        if(s.size()==1)
        {
            cout<<0<<endl;
            continue;
        }
        bool p=false;
        bool q=false;
        ll max1,max2;
        ll r=1,st=1,j=n-1;
        for(ll i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1] and !p) r++;
            else p=true;
            if(arr[n-i-1]==arr[n-1] and !q) 
            {
                st++;
            }
            else q=true;
        }
        ll temp;
        //cout<<r<<" "<<st<<" ";
        if(r>=st) temp=arr[0];
        else temp=arr[n-1];
        //cout<<temp<<" ";
        for(ll i=0;i<n;i++)
        {
            if(temp!=arr[i])
            {
                left=i;
                break;
            }
        }
        for(ll i=n-1;i>=left;i--)
        {
            if(temp!=arr[i])
            {
                right=i;
                break;
            }
        }
        cout<<right-left+1<<endl;
    }
}