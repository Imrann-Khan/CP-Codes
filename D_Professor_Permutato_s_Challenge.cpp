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
const int N = 1e7 + 1;
vector<bool> prime(N);
vector<int> pr;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> res(n + 1);

    if (k == n - 1)
    {
        cout << "2 1 ";
        for (int i = 3; i <= n; i++)
        {
            cout << i << " ";
        }
    }
    else
    {
        for (int i = 1; i <= k; i++)
        {
            res[i] = i;
        }
        if (k < n)
            res[n] = k + 1;
        for (int i = k + 1; i < n; i++)
        {
            res[i] = i + 1;
        }

        for (int i = 1; i <= n; i++)
            cout << res[i] << " ";
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
