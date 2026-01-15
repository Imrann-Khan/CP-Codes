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
        ll m;
        cin >> n >> m;
        if (m < n || m > n * (n + 1) / 2) 
        {
            cout << "-1\n";
            return;
        }
        ll ans = 1;
        rep(i,1,n) 
        {
            if (n + i * (i - 1) / 2 <= m and m <= i * (2 * n + 1 - i) / 2) 
            {
                ans = i;
                break;
            }
        }
        ll diff = m - n - ans * (ans - 1) / 2;
        vector<int> a(n + 1, 1);
        for (int i = 1; i < ans; ++i) 
            a[i] = ans;
        int ken = ans + 1;
        while (diff > 0 and ken <= n) 
        {
            int cnt;
            if (diff < ans - 1) 
                cnt = diff;
            else 
                cnt = ans - 1;
            a[ken] = cnt + 1;
            diff -= cnt;
            ++ken;
        }

        cout << ans << "\n";
        for (int i = 1; i <= n; ++i) {
            if (i != ans) {
                cout << a[i] << " " << i << "\n";
            }
        }
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
