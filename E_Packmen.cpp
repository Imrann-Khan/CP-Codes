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

bool CanEat(vector<ll> p, vector<ll> ast, ll posT)
{
    int mx = (int)ast.size();
    int j = 0;
    rep(i, 0, (int)p.size())
    {
        int cur = j;
        while (j < mx and ast[j] - ast[cur] + min(abs(p[i] - ast[cur]), abs(p[i] - ast[j])) <= posT)
            j++;
    }
    if (j == mx)
        return true;
    else
        return false;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> p;
    vector<ll> ast;
    rep(i, 0, n - 1)
    {
        cin >> s[i];
        if (s[i] == 'P')
            p.push_back(i + 1);
        else if (s[i] == '*')
            ast.push_back(i + 1);
    }
    ll l = 1, r = 2 * n;
    ll ans = -1;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (CanEat(p, ast, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
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
