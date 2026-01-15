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
const int MAXN = 1e7 + 1;
vector<bool> prime(MAXN, 1);
vector<int> v;

void Sieve()
{
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

void X()
{
    for (int i = 1; i * i <= MAXN; i++)
    {
        for (int j = 1; j * j * j * j <= MAXN; j++)
        {
            int tmp = i * i + j * j * j * j;
            if (tmp < MAXN and prime[tmp])
            {
                v.push_back(tmp);
                prime[tmp] = false;
            }
        }
    }
    sort(v.begin(), v.end());
}

void solve()
{
    int n;
    cin >> n;
    int ans = upper_bound(v.begin(), v.end(), n) - v.begin();
    cout << ans << endl;
}

signed main()
{
    Sieve();
    X();
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
