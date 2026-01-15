#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (i & 1)
            sum -= x;
        else
            sum += x;
    }
    cout << sum << endl;
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