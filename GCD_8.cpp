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
    vector<bool> v(n + 1, false);
    vector<int> ans(n + 1);
    ans[1] = 1;
    int cnt = 2;
    for (int i = 2; i <= n; i++)
    {
        if (2 * ans[i - 1] <= n)
        {
            if (!v[2 * ans[i - 1]])
            {
                ans[i] = 2 * ans[i - 1];
                v[2 * ans[i - 1]] = 1;
            }
            else
            {
                // cout << i << " " << cnt << " ";
                while (v[cnt])
                {
                    cnt++;
                }
                ans[i] = cnt;
                v[cnt] = 1;
            }
        }
        else
        {
            // cout << i << " " << cnt << " ";
            while (v[cnt])
            {
                cnt++;
            }
            ans[i] = cnt;
            v[cnt] = 1;
        }
    }
    // cout << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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