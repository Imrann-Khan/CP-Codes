#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main()
{
    fast
    ll n, t, y, sum;
    cin>>t;
    while(t--)
    {
        ll c=0, f=0, sum=0;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++)
        {
            cin>>v[i];
        }
        //sort(v.begin(), v.end());
        ll mx=0;
        for(ll i=0; i<n-1; i++)
        {
            if(v[i]>mx)
            {
                mx=v[i];
            }
        }
        y= mx+v[n-1];
        cout<<y<<endl;
    }
    return 0;
}