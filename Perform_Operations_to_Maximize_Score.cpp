#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

int BD(int cnt, int dif, ll k)
{
    ll min = 0, max = 1000000000;
    ll mid, x, prvmd;
    while (min <= max)
    {
        mid = min + (max - min) / 2;
        x = abs(cnt * mid - dif);
        if (x <= k)
        {
            prvmd = mid;
            min = mid + 1;
        }
        else
            max = mid - 1;
    }
    return prvmd;
}

void solve()
{
    ll n;
    ll k;
    cin >> n >> k;
    bool j = 0;
    pair<ll, ll> a[n];
    ll v[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first;
        v[i] = a[i].first;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].second;
        if (a[i].second == 1)
            j = 1;
    }
    sort(a, a + n);
    sort(v, v + n);
    ll ans = a[n - 1].first;
    if (a[n - 1].second == 1)
        cout << a[(n - 2) / 2].first + k + a[n - 1].first << endl;
    else
    {
        if (!j)
        {
            cout << a[(n - 2) / 2].first + a[n - 1].first << endl;
            return;
        }
        int ans = 0;
        ll l = 0, r = v[n - 1], mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            ll b = k;
            for (ll i = n - 2; i >= 0; i--)
            {
                if (v[i] < mid and a[i].second == 1)
                {
                    ll p = b;
                    if (b >= mid - v[i])
                        b -= mid - v[i];
                    v[i] += min(p, mid - v[i]);
                    if (b == 0)
                        break;
                }
            }
            sort(v, v + n - 1);
            if (v[(n / 2) - 1] >= mid)
            {
                ans = max(1LL * ans, mid + v[n - 1]);
                l = mid + 1;
            }
            else
                r = mid - 1;
            for (int i = 0; i < n; i++)
                v[i] = a[i].first;
        }
        ll pos = -1;
        for (ll i = 0; i < n; i++)
        {
            if (a[i].second == 1)
                pos = i;
        }
        vector<ll> vt;
        for (int i = 0; i < n; i++)
        {
            if (i != pos)
                vt.push_back(v[i]);
        }
        ans = max(1LL * ans, vt[(n / 2) - 1] + v[pos] + k);
        cout << ans << endl;
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