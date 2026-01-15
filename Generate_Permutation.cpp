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
    if (n % 2 == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<ll> p(n);
        ll left = 1, right = n;

        for (ll i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                p[i] = right--;
            }
            else
            {
                p[i] = left++;
            }
        }
        for (ll i = 0; i < n; ++i)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
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