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
    vector<int> a(n + 1);
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ind[a[i]] = i;
    }
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != i)
        {
            int g = a[i];
            int f = ind[i];
            k = __gcd(k, ind[i] - i);
            swap(a[i], a[ind[i]]);
            ind[i] = i;
            ind[g] = f;
        }
    }
    cout << k << endl;
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