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
    ld a, b, c, k;
    cin >> a >> b >> c >> k;
    ld ans = k / (k + 1);
    ld l = 0, r = a;
    ld res;
    while (r > l)
    {
        ld mid = l + (r - l) / 2;
        res = mid;
        ld temp = mid / a;
        temp = pow(temp, 2);
        if (temp > ans)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << res << endl;
}

signed main()
{
    fast
        ll t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        cout << "Case " << c << ": ";
        solve();
        c++;
    }
}
