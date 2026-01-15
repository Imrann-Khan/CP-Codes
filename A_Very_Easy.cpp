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

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        int l = 0, r = n - 1;
        int ans = 0;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (a[m] >= x)
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        if (a[ans] == x)
        {
            cout << "Yes " << ans + 1 << endl;
        }
        else
            cout << "No " << ans + 1 << endl;
    }
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
