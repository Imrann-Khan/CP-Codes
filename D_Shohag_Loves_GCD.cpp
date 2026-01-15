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
const int N = 1e5 + 7;
vector<int> fr[N];

void pre()
{
    for (int p = 1; p < N; p++)
    {
        for (int i = p + p; i <= N; i += p)
            fr[i].push_back(p);
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<int> s(m + 1);
    rep(i, 1, m)
            cin >>
        s[i];
    vector<ll> v(n + 1, 0);
    rep(i, 1, n)
    {
        set<int> nai;
        for (auto j : fr[i])
            nai.insert(v[j]);
        for (int k = m; k >= 1; k--)
        {
            if (nai.find(s[k]) == nai.end())
            {
                v[i] = s[k];
                break;
            }
        }
        if (v[i] == 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    rep(i, 1, n) cout << v[i] << " ";
    cout << endl;
}

signed main()
{
    fast
    pre();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
