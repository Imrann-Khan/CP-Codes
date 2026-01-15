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

bool valid(vector<ll> &x, int n, int c, int dis)
{
    int cnt = 1;
    ll prv = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x[i] - prv >= dis)
        {
            cnt++;
            prv = x[i];
        }
    }
    return (cnt >= c);
}

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<ll> x(n);
    rep(i, 0, n - 1) cin >> x[i];
    sort(x.begin(), x.end());
    ll l = 0, r = *max_element(x.begin(), x.end());
    ll ans = -1;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        // cout << mid << " " << valid(x, n, c, mid) << endl;
        if (valid(x, n, c, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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
