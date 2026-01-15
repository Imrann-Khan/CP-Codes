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
    int n;
    cin >> n;
    vector<int> v;
    if (n & 1 and n <= 25)
    {
        cout << -1 << endl;
        return;
    }
    int cnt = 2;
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; i += 2)
        {
            cout << cnt << " " << cnt << " ";
            cnt++;
        }
    }
    else
    {
        cnt = 14;
        cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 ";
        for (int i = 14; i <= n / 2; i++)
        {
            cout << i << " " << i << " ";
        }
    }
    cout << endl;
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
