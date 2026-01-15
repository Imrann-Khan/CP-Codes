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
    cin >> n;
    pair<int, int> ans;
    int tmp = 0;
    rep(i, 1, n / 2)
    {
        if (__gcd(i, n - i) == 1)
        {
            if (i > tmp and i < n - i)
            {
                tmp = i;
                ans.first = i;
                ans.second = n - i;
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
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
