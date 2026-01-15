#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pi 3.141592653589793238462643383279502884197
using namespace std;

const ll MOD = 1e9 + 7;

void solve()
{
    int n;
    ll k;
    cin >> n;
    ll arr[n];
    rep(i, 0, n - 1) cin >> arr[i];
    vector<vector<int>> v;
    for (ll i = 1; i < pow(2, n); i++)
    {
        ll tmp = i;
        vector<int> t;
        for (ll j = 0; j < n; j++)
        {
            ll r = tmp % 2;
            tmp /= 2;
            if (r)
                t.push_back(arr[j]);
        }
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << "[";
        for (auto j : i)
            cout << j;
        cout << "]";
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
