#include <bits/stdc++.h>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
typedef long long ll;

vector<bool> prime(1e6, true);
vector<int> ans(1e6, 0);

bool chk(int n)
{
    string s = to_string(n);
    while (n != 0)
    {
        if (n % 10 == 0)
            return false;
        n /= 10;
    }
    for (int i = 1; i < s.size(); i++)
    {
        string t = s.substr(i);
        if (!prime[stoi(t)])
            return false;
    }
    return true;
}

void Sieve()
{
    prime[0] = prime[1] = false;
    for (int p = 2; p < 1e6; p++)
    {
        if (prime[p] == true)
        {
            if (chk(p))
                ans[p] = 1;
            for (int i = p + p; i < 1e6; i += p)
            {
                prime[i] = false;
            }
        }
        ans[p] += ans[p - 1];
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

signed main()
{
    fast
    Sieve();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}