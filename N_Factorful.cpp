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

const int MAX = 1000001;

vector<int> spf(MAX, 0);
vector<int> v[11];

void SPF()
{
    for (int i = 2; i < MAX; i++)
    {
        if (spf[i] == 0)
        {
            for (int j = i; j < MAX; j += i)
            {
                spf[j]++;
            }
        }
    }
    for (int i = 1; i < MAX; i++)
        v[spf[i]].push_back(i);
}

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    int ansA = upper_bound(v[n].begin(), v[n].end(), a - 1) - v[n].begin();
    int ansB = upper_bound(v[n].begin(), v[n].end(), b) - v[n].begin();
    cout
        << ansB - ansA << endl;
}

signed main()
{
    fast
    SPF();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
