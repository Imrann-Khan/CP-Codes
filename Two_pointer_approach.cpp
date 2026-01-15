#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

using namespace std;


signed main()
{
    fast
    ll n,x; cin>>n>>x;
    ll arr[n];
    for(ll i=0;i<n;i++) cin>>arr[i];
    ll low=0,high=n-1;
    while(low<high)
    {
        if(low==high) break;
        if(arr[low]+arr[high]==x)
        {
            cout<<low<<","<<high<<endl;
            break;
        }
        else if((arr[low]+arr[high]<x)) low++;
        else high--;
    }
}