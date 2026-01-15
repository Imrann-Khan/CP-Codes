#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;


ll lower_bound(ll arr[], ll N, ll X)
{
    ll mid;
    ll low = 0;
    ll high = N;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (X <= arr[mid]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    if(low < N && arr[low] < X) {
       low++;
    }
    return low;
}
 
ll upper_bound(ll arr[], ll N, ll X)
{
    ll mid;
    ll low = 0;
    ll high = N;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (X >= arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    if(low < N && arr[low] <= X) {
       low++;
    }
    return low;
}

signed main() {
    fast
    ll t; cin>>t;
    while(t--)
    {
        ll k,x;
        cin>>k>>x;
        ll cnt=0;
        
        cout<<cnt<<endl;
    }
}
