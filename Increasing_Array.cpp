#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    fast
    ll n; cin>>n;
    ll arr[n];
    ll tmp=0;
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0) continue;
        if(arr[i]<arr[i-1])
        {
            cnt+=(arr[i-1]-arr[i]);
            arr[i]+=(arr[i-1]-arr[i]);
        }
    }
    //for(ll i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<cnt<<endl;
}