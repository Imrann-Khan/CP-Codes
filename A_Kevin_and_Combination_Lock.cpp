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

void solve()
{
    string x;
    cin >> x;
    int n;
    string s = "";
    for (int i = x.size() - 1; i >= 0; i--)
    {
        if (x[i] == '3' and x[i - 1] == '3' and i > 1)
        {
            i--;
        }
        else
        {
            s = x[i] + s;
        }
    }
    // cout << s << endl;
    ll a = stoi(s);
    if (a % 33 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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
