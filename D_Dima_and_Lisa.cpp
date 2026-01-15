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
        if (n < 9)
            cout << 1 << endl
                 << n << endl;
        else
        {
            cout << 3 << endl
                 << 3 << " ";
            for (int i = 2; i * 2 <= n; i++)
            {
                if (chkPrime(i) and chkPrime(n - i - 3))
                {
                    cout << i << " " << n - i - 3 << endl;
                    break;
                }
            }
        }
    }
}
