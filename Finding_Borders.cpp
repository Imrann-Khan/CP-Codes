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

static const ll MOD=1e9+7;

void solve()
{
    string s;
    cin>>s;
    int p1=5,power=1;
    ll l1=0,r1=0;

    for(int i=0;i<s.size()-1;i++)
    {
        l1 = (l1 + (s[i] - 'a' + 1) * power) % MOD;
        power = (power * p1) % MOD;
        r1 = (r1 * p1 + (s[s.size() - i - 1] - 'a' + 1)) % MOD;
        if (l1 == r1)
        {
            cout << i + 1 << " ";
        }
    }
    cout<<endl;
}

signed main()
{
    fast

        ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
