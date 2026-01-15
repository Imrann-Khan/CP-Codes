#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 1; i < n; i += 2)
    {
        if (abs(a[i - 1] - a[i]) <= k)
        {
            k -= abs(a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
        else
        {

            a[i] += k;
            k = 0;
        }
    }
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    int ans = 0;
    if (n & 1)
    {
        ans += a[a.size() - 1];
    }
    for (int i = 1; i < n; i += 2)
    {
        ans += abs(a[i - 1] - a[i]);
    }
    cout << ans << endl;
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