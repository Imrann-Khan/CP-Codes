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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> sum;
    ll x = 0;
    for (int p = n - 1; p >= 0; p--)
    {
        sum.push_back(x);
        if (s[p] == '1')
            x++;
        else
            x--;
    }
    // for (auto i : sum)
    //     cout << i << " ";
    // cout << endl;
    sort(sum.begin(), sum.end(), greater<ll>());
    // for (auto i : sum)
    //     cout << i << " ";
    // cout << endl;
    ll ps = 0;
    ll ans = -1;
    for (ll m = 0; m <= n - 2; m++)
    {
        ps += sum[m];
        if (ps >= k)
        {
            ans = m + 2;
            break;
        }
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
