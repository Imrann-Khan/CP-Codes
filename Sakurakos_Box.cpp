#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll mod_inv(ll a, ll b)
{
    int result = 1;
    while (b > 0)
    {
        if (b % 2)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll prvSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prvSum += (a[i] % MOD);
    }
    prvSum -= a[0];
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += ((a[i] % MOD) * (prvSum % MOD)) % MOD;
        prvSum -= (a[i + 1] % MOD);
    }
    ll cnt = n * (n - 1);
    cnt /= 2;
    ll y = mod_inv(cnt % MOD, MOD - 2);
    cout << ((ans % MOD) * (y % MOD)) % MOD << endl;
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