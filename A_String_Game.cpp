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
const int N = 1e7 + 1;
vector<bool> prime(N);
vector<int> pr;

void SieveOfEratosthenes()
{
    for (int p = 2; p * p <= N; p++)
    {
        prime[p] = true;
    }
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }

    // for (int p = 2; p <= N; p++)
    //     if (prime[p])
    //         pr.push_back(p);
}

bool valid(ll m, string s, string p, vector<ll> t)
{
    const ll n = s.size();
    vector<bool> chk(n, 1);
    string r;
    for (ll i = 0; i < m; i++)
        chk[t[i] - 1] = 0;
    for (ll i = 0; i < n; i++)
    {
        if (chk[i])
            r += s[i];
    }
    ll a = r.size();
    ll b = p.size();
    if (a < b)
        return 0;
    ll j = 0;
    for (ll i = 0; i < a; i++)
    {
        if (j == b)
            return 1;
        if (r[i] == p[j])
            j++;
    }
    if (j == b)
        return 1;
    else
        return 0;
}

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

void solve()
{
    string s, p;
    cin >> s >> p;
    ll n = s.size();
    vector<ll> a(n);
    rep(i, 0, n - 1) cin >> a[i];

    ll l = 0, r = n, m, ans = -1;
    while (l <= r)
    {
        ll m = (l + r) >> 1;

        if (valid(m, s, p, a))
        {
            l = m + 1;
            ans = m;
        }
        else
            r = m - 1;
    }
    cout << ans << endl;
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
