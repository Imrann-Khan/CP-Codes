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
const int N = 1e7 + 7;
vector<bool> prime(N);
vector<int> pr;

ll memo[10000 + 7];

ll a, b, c, d, e, f, n;
ll fn(ll n)
{
    if (memo[n] != -1)
        return memo[n];
    ll sum = 0;
    rep(i, 1, 6)
        sum += fn(n - i) % N;
    memo[n] = sum;
    return sum;
}

void solve()
{
    memset(memo, -1LL, sizeof(memo));
    cin >> memo[0] >> memo[1] >> memo[2] >> memo[3] >> memo[4] >> memo[5] >> n;
    cout << fn(n) % N << endl;
}

signed main()
{
    fast
        ll t;
    cin >> t;
    int cnt = 1;
    while (t--)
    {
        cout << "Case " << cnt++ << ": ";
        solve();
    }
}
