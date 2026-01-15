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

int findMex(vector<int> arr)
{
    int N=arr.size();
    sort(arr.begin(), arr.end());
    int mex = 0;
    for (int idx = 0; idx < N; idx++)
    {
        if (arr[idx] == mex)
        {
        mex += 1;
        }
    }
    return mex;
}


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n - 1) cin >> a[i];

    int steps = min(k, k % 2 + 2);
    for (int op = 0; op < steps; ++op) {
        vector<int> freq(n + 2, 0);
        for (int x : a) freq[x]++;
        int mex = 0;
        while (freq[mex]) ++mex;
        vector<int> b = a;
        for (int j = 0; j < n; ++j) {
            if (a[j] > mex) {
                b[j] = mex;
            } else if (a[j] < mex && freq[a[j]] > 1) {
                b[j] = mex;
            } else {
                b[j] = a[j];
            }
        }
        a = b;
    }
    ll ans = 0;
    for (auto i : a) ans += i;
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
