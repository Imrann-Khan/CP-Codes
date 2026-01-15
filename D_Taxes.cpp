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

bool chkPrime(ll n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

signed main()
{
    fast
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (chkPrime(n))
            cout << 1 << endl;
        else if (n % 2 == 0 or chkPrime(n - 2))
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
}
