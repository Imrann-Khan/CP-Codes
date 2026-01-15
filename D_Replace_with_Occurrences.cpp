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
    vector<int> b(n), a(n);
    map<int, vector<int>> mp;
    rep(i, 0, n - 1) {
        cin >> b[i];
        mp[b[i]].push_back(i);
    }

    int cnt = 1;
    for (auto &it : mp) {
        int mx = it.first;
        int sz = it.second.size();
        if (sz % mx != 0) {
            cout << -1 << endl;
            return;
        }
        for (int i = 0; i < sz; ++i) {
            a[it.second[i]] = cnt;
            if ((i + 1) % mx == 0) cnt++;
        }
    }
    for (auto i : a) cout << i << " ";
    cout << endl;
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
