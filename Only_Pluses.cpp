#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

void solve()
{
    vector<ll> v(3);
    for (ll i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    for (ll i = 0; i < 5; i++)
    {
        sort(v.begin(), v.end());
        v[0]++;
    }
    cout << v[0] * v[1] * v[2] << "\n";
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