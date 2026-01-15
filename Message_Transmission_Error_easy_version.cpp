#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

void solve()
{
}

signed main()
{
    // fast
    //     ll t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    string s;
    cin >> s;
    bool f = true;
    if (s.size() & 1)
    {
        for (int i = s.size() - 1; i > s.size() / 2; i--)
        {
            if (s[i] != s[i - s.size() / 2])
            {
                f = 0;
                break;
            }
        }
    }
    else
    {
        for (int i = s.size() - 1; i > s.size() / 2; i--)
        {
            if (s[i] != s[i - s.size() / 2])
            {
                f = 0;
                break;
            }
        }
    }
    if (f)
    {
        cout << "YES\n";
        cout << s.substr(0, s.size() / 2 + 1);
    }
    else
        cout << "NO\n";
}