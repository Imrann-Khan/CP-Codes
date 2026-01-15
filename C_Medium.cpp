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
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long sum = a[i] + a[j];
            int l = j, r = n - 1;
            int mid;
            while (r > l)
            {
                int mid = (l + r + 1) >> 1;
                if (a[mid] < sum)
                    l = mid;
                else
                    r = mid - 1;
            }
            ans += (l - j);
        }
    }
    cout << ans << endl;
}

signed main()
{
    fast

        ll t;
    cin >> t;
    int k = t;
    while (t--)
    {
        cout << "Case " << k - t << ": ";
        solve();
    }
}
