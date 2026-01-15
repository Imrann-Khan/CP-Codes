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
    int y = n;
    vector<int> cnt(n + 1, 0);
    set<int> s;
    while (y--)
    {
        int x;
        cin >> x;
        s.insert(x);
        cnt[x]++;
    }
    if (s.size() == 1)
    {
        cout << "Yes\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
            continue;
        if (cnt[i])
        {
            if (cnt[i] > 2)
            {
                cnt[i + 1] += cnt[i] - 2;
                cnt[i] = 2;
                // cout << i << " " << cnt[i] << endl;
                // cout << i + 1 << " " << cnt[i + 1] << endl;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] != 0 and cnt[i] & 1)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
