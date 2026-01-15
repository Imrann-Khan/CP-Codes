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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n-1) cin >> a[i];
    rep(i, 0, n-1) cin >> b[i];

    vector<int> p(n+2, 0), both(n+2, 0);
    rep(i, 0, n-1) 
    {
        if (a[i] == b[i]) 
        {
            both[a[i]]++;
            p[a[i]] += 2;
        } 
        else 
        {
            p[a[i]]++;
            p[b[i]]++;
        }
    }

    int c1 = 0;
    while (c1 <= n+1 && p[c1] > 0) c1++;

    vector<int> L;
    rep(x, 0, c1-1) 
    {
        if (p[x] >= 1 && both[x] == 0)
            L.PB(x);
    }

    int c2 = (L.size() >= 2 ? L[1] : n+1);

    cout << min(c1, c2) << "\n";
}

signed main()
{
    fast
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
