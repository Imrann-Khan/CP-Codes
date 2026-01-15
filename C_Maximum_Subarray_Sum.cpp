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

ll maximum_subarray_sum(vector<ll> &a, int n)
{
    vector<ll> dp(n, 0);
    dp[0] = a[0];
    rep(i, 1, n - 1)
    {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    }
    return *max_element(dp.begin(), dp.end());
}

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    string s;
    cin >> s;
    rep(i, 0, n - 1) cin >> a[i];
    int pos = -1;
    rep(i, 0, n - 1)
    {
        if (s[i] == '0')
        {
            if (pos == -1)
                pos = i;
            a[i] = -1e18;
        }
    }
    if (pos == -1)
    {
        if (maximum_subarray_sum(a, n) == k)
        {
            cout << "Yes\n";
            rep(i, 0, n - 1) cout << a[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    ll l = -1e18, r = 1e18;
    while (r > l)
    {
        ll mid = (r + l) >> 1;
        a[pos] = mid;
        // cout << mid << endl;
        ll temp = maximum_subarray_sum(a, n);
        if (temp == k)
        {
            cout << "Yes\n";
            rep(i, 0, n - 1) cout << a[i] << " ";
            cout << endl;
            return;
        }
        else if (temp < k)
        {
            l = mid;
        }
        else
            r = mid;
    }
    cout << "No\n";
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
