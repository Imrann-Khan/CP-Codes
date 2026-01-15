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
    map<int, int> fr;
    while (n--)
    {
        int x;
        cin >> x;
        if (fr.find(x) != fr.end())
            fr[x]++;
        else
            fr.insert({x, 1});
    }
    // for (auto it : fr)
    //     cout << it.first << " " << it.second << endl;
    // cout << endl;
    int ans = 0;
    bool t = 1;
    int cnt = 0;
    for (auto it : fr)
    {
        if (it.second == 1)
        {
            cnt++;
        }
    }
    if (cnt & 1)
    {
        t = 0;
        cnt /= 2;
        cnt++;
        ans += (cnt * 2);
    }
    else
    {
        t = 1;
        cnt /= 2;
        ans += (cnt * 2);
    }
    for (auto it : fr)
    {
        if (it.second != 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
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
