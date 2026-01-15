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

const int MAX = 1e6 + 1;

vector<ll> spf(MAX);
vector<ll> pf;

void SPF()
{
    for (int i = 1; i < MAX; i++)
        spf[i] = i;
    for (int i = 2; i * i < MAX; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    for (int i = 2; i < MAX; i++)
    {
        if (spf[i] == i)
            pf.push_back(i);
    }
}

signed main()
{
    fast
    SPF();
    int sz = pf.size() + 1;
    vector<ll> prfxsum(sz);
    partial_sum(pf.begin(), pf.end(), prfxsum.begin() + 1);
    ll t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        ll val = lower_bound(pf.begin(), pf.end(), spf[k]) - pf.begin();
        cout << prfxsum[val + 1] * k << endl;
    }
}
