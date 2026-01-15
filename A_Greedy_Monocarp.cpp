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
    vector<int> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    sort(a.begin(), a.end(), greater<>());
    // rep(i, 0, n - 1)
    //         cout
    //     << a[i] << " ";
    // cout << endl;
    int tmp = k;
    int ans = 0;
    rep(i, 0, n - 1)
    {
        if (tmp >= a[i])
            tmp -= a[i];
        else
            break;
    }
    cout << tmp << endl;
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
