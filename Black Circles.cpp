#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    ll path = 1LL * abs(xt - xs) * abs(xt - xs) + 1LL * abs(yt - ys) * abs(yt - ys);
    for (int i = 0; i < n; i++)
    {
        ll fd = 1LL * abs(xt - v[i].first) * abs(xt - v[i].first) + 1LL * abs(yt - v[i].second) * abs(yt - v[i].second);
        if (fd <= path)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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