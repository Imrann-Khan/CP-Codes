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
    int n, k;
    cin >> n >> k;
    ll arr[n];
    rep(i, 0, n - 1) cin >> arr[i];
    bool f;
    bool c = 0;
    rep(i, 0, n - 1)
    {
        f = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (abs(arr[i] - arr[j]) % k == 0)
            {
                // cout << arr[i] << " " << arr[j] << " ";
                f = 1;
                break;
            }
        }
        if (!f)
        {
            cout << "YES\n";
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "NO\n";
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
