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

const int MAX = 10000001;

vector<int> spf(MAX, 1);
vector<int> pf;
vector<bool> pr(MAX, 1);

void Sieve()
{
    spf[0] = 0;
    spf[1] = 0;
    for (int i = 2; i * i < MAX; i++)
    {
        if (pr[i] == 1)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                pr[j] = 0;
            }
        }
    }
    for (int i = 2; i < MAX; i++)
    {
        if (pr[i])
            pf.push_back(i);
    }
}

void SPF()
{
    spf[0] = 0;
    for (int i = 2; i < MAX; i++)
    {
        if (spf[i] == 1)
        {
            for (int j = i; j < MAX; j += i)
            {
                if (spf[j] == 1)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> getFact(int x)
{
    vector<int> fact;
    while (x != 1)
    {
        fact.push_back(spf[x]);
        x /= spf[x];
    }
    return fact;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    set<int> prime;
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        while (a[i] > 1)
        {
            prime.insert(spf[a[i]]);
            a[i] /= spf[a[i]];
        }
    }
    for (auto it : pf)
    {
        if (prime.find(it) == prime.end())
        {
            cout << it << endl;
            return;
        }
    }
}

signed main()
{
    fast
    Sieve();
    SPF();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
