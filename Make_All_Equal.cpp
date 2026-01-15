#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(cnt.begin(), cnt.end(), greater<ll>());
    cout << n - cnt[0] << endl;
}

signed main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}