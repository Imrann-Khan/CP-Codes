#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

int split(int n, int k)
{
    if (n <= k)
        return 1;
    return 1 + split(n - k + 1, k);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    cout << split(n, k) << endl;
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