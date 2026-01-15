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

ll intPower(ll base, ll exp)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

bool canFindSubsegment(int mid, const vector<pair<int, int>> &runs)
{
    for (int i = 0; i + 1 < (int)runs.size(); i++)
    {
        if (runs[i].first != runs[i + 1].first)
        {
            if (runs[i].second >= mid && runs[i + 1].second >= mid)
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    vector<pair<int, int>> runs;
    runs.push_back({a[0], 1});
    for (int i = 1; i < n; i++)
    {
        if (a[i] == runs.back().first)
        {
            runs.back().second++;
        }
        else
        {
            runs.push_back({a[i], 1});
        }
    }
    int ans = 1;
    int l = 1, r = 2 * n;
    while (r >= l)
    {
        int mid = (r + l) >> 1;
        // cout << mid << endl;
        if (canFindSubsegment(mid, runs))
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << 2 * ans << endl;
}

signed main()
{
    fast
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}