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

ll con(int k, int a[], int b)
{
    ll ans = 0;
    int z = k;
    for (int i = 0; i < k; i++)
    {
        ans += a[i] * pow(b, (z - i - 1));
    }
    return ans;
}

signed main()
{
    fast int n, m, ax, bx;
    cin >> n >> ax;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    cin >> m >> bx;
    int b[m];
    rep(i, 0, m - 1) cin >> b[i];
    // cout << con(n, a, ax) << " " << con(m, b, bx) << endl;
    if (con(n, a, ax) == con(m, b, bx))
        cout
            << "=\n";
    else if (con(n, a, ax) < con(m, b, bx))
        cout << "<\n";
    else
        cout << ">\n";
    return 0;
}
