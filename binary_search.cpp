#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll lower_bound(ll a[],ll n,ll key)
{
    ll low=0,high=n-1,res=0;
    ll mid;
    while(low<=high && low>=0 && high<n)
    { 
        mid=low+(high-low)/2;
        if(key==a[mid]) 
        {
            res=mid;
            low=mid+1;
        }
        else if(key<a[mid])
        {
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}

int main()
{
    ll t;
    ll n,k,a[50001];
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        cin>>n>>k;
        if(k>n) return 0;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        ll p=a[n-k];
        ll d=lower_bound(a,n,p);
        cout<<a[d]<<endl;
    }
    return 0;
}
