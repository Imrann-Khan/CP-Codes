#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<pair<ll, ll>, ll> mp;
    ll ans = 0;
    for (ll e : a) {
        ll con1 = e % x;
        ll con2 = e % y;
        ans += mp[{(x - con1) % x, con2}];
        mp[{con1, con2}]++;
    }

    cout << ans << endl;
}

signed main()
{
    fast
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}