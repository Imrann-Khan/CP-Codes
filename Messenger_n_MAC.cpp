#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

bool sortbysec(const pair<ll,ll>&a, const pair<ll,ll>&b){
       return (a.second<b.second);
}

signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        ll n,l;
        cin>>n>>l;
        vector<pair<ll,ll> > v(n);
        for(ll i=0;i<n;i++)
        {
            cin>>v[i].second>>v[i].first;
        }
        ll ans=0;
        sort(v.begin(),v.end());
        for (ll i= 0 ; i < n ; i++) {
            priority_queue<ll> s;
            ll cur = 0;
            for (ll j = i ; j < n ; j++) {
                s.push(v[j].second);
                cur += v[j].second;
                while (!s.empty() && v[j].first - v[i].first + cur > l) {
                    cur -= s.top();
                    s.pop();
                }
                ans = max(ans, (ll)s.size());
            }
        }
        cout<<ans<<endl;
    }
}