#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

using namespace std;

bool solve(ll arr[],ll k,ll n)
{
    unordered_set<ll> s;
    ll pr=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]==k) return true;
        if(s.find(arr[i]-k)!=s.end()) return true;
        s.insert(arr[i]);
    }
    return false;
}

signed main()
{
    fast
    ll n,k; cin>>n>>k;
    ll presum[n];
    ll pr=0;
    for(ll i=0;i<n;i++)
    {
        cin>>presum[i];
        presum[i]+=pr;
        pr = presum[i];
    }
    if(solve(presum,k,n)) cout<<"YES\n";
    else cout<<"NO\n";
}