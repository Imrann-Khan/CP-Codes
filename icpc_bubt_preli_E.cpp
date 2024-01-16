#include <bits/stdc++.h>
#define ll long long int
#define fast ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    fast
    ll t;
    cin>>t;
    for (ll i = 1; i <= t; i++) {
        ll n;
        cin>>n;
        ll a[n];
        for (ll j = 0; j < n; j++) {
            cin>>a[j];
        }
        ll ans = n * (n + 1) / 2;
        ll cnt = 1;
        for (ll j = 1; j < n; j++) {
            if (a[j] != a[j - 1]) {
                ans -= cnt * (cnt + 1) / 2;
                cnt = 0;
            }
            cnt++;
        }
        ans -= cnt * (cnt + 1) / 2;
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}