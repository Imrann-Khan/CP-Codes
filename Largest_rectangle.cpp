
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main()
{
    fast
    ll n; cin>>n;
    ll arr[n], ps[n], ns[n];
    for(ll i=0;i<n;i++) 
    {
        cin>>arr[i];
        ps[i]=-1;
        ns[i]=n;
    }
    ll ls=0,as=n;
    for(ll i=1,j=n-2;i<n && j>=0;i++,j--)
    {
        if(arr[i]<arr[i-1])
        {
            if(arr[i]>arr[ls] and ls!=-1)
            {
                ps[i]=ls;
                ls=i;
            }
            else 
            {
                if(arr[i]<arr[ls] and ls!=-1) ps[i]=ps[i-1];
            }
        }
        else 
        {
            if(arr[i-1]<arr[ls] and ls!=-1)
            {
                ps[i]=i-1;
            }
            else ps[i]=ps[i-1];
        }
        if(arr[j]<arr[j+1])
        {
            if(arr[j]<arr[ls])
            {
                ns[j]=as;
                as=i;
            }
        }
        else
        {
            if(arr[j+1]<arr[as])
            {
                ns[i]=i-1;
            }
        }
    }
    for(ll i=0;i<n;i++) cout<<ps[i]<<" ";
    cout<<endl;
    for(ll i=0;i<n;i++) cout<<ns[i]<<" ";
    cout<<endl;
}


/*
7
6 2 5 4 1 5 6
*/