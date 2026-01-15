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


ll findNextNumber(ll n) 
{
    ll c0 = n & -n;
    ll c1 = n + c0;
    ll c2 = (((n ^ c1) / c0) >> 2);
    return c1 | c2;
}

void solve()
{
    ll n;
    cin>>n;
    cout<<findNextNumber(n)<<endl;
}

signed main()
{
    fast

    ll t;
    cin >> t;
    ll c = 1;
    while (t--)
    {
        cout << "Case " << c << ": ";
        solve();
        c++;
    }
}
