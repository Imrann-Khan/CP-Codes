#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    vector<int> a;
    bool got = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            a.push_back(1);
            got = 0;
        }
        else
        {
            if (!got)
            {
                a.push_back(0);
                got = 1;
            }
        }
    }
    int cnt0 = 0, cnt1 = 0;
    for (auto i : a)
    {
        if (i == 1)
            cnt1++;
        else
            cnt0++;
    }
    if (cnt1 > cnt0)
        cout << "Yes\n";
    else
        cout << "No\n";
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