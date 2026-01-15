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
    ll n, m;
    cin >> n >> m;
    char a[n][m];
    rep(i, 0, n - 1)
    {
        rep(j, 0, m - 1) cin >> a[i][j];
    }
    pair<int, char> map[n][m];
    int ans = 0;
    rep(i, 0, n - 1)
    {
        rep(j, 0, m - 1)
        {
            if (i == 0)
            {
                if (a[i][j] != '?')
                {
                    if (a[i][j] == 'U' or (a[i][j] == 'L' && j == 0))
                        map[i][j] = {0, a[i][j]};
                    else if (a[i][j] == 'U' || (a[i][j] == 'R' && j == m - 1))
                        map[i][j] = {0, a[i][j]};
                    else
                        map[i][j] = {1, a[i][j]};
                }
            }
            else if (i == n - 1)
            {
                if (a[i][j] != '?')
                {
                    if (a[i][j] == 'D' || (a[i][j] == 'L' && j == 0))
                        map[i][j] = {0, a[i][j]};
                    else if (a[i][j] == 'D' || (a[i][j] == 'R' && j == m - 1))
                        map[i][j] = {0, a[i][j]};
                    else
                        map[i][j] = {1, a[i][j]};
                }
            }
            else
            {
                if (a[i][j] != '?')
                {
                    vector<pair<int, char>> v;
                    if (a[i + 1][j] != '?')
                        v.push_back(map[i + 1][j]);
                    if (a[i - 1][j] != '?')
                        v.push_back(map[i - 1][j]);
                    if (a[i][j + 1] != '?')
                        v.push_back(map[i][j + 1]);
                    if (a[i][j - 1] != '?')
                        v.push_back(map[i][j - 1]);
                    sort(v.begin(), v.end());
                    map[i][j].first = v.rbegin()->first;
                }
                else
                {
                    vector<pair<int, char>> v;
                    if (a[i + 1][j] != '?')
                        v.push_back(map[i + 1][j]);
                    if (a[i - 1][j] != '?')
                        v.push_back(map[i - 1][j]);
                    if (a[i][j + 1] != '?')
                        v.push_back(map[i][j + 1]);
                    if (a[i][j - 1] != '?')
                        v.push_back(map[i][j - 1]);
                    sort(v.begin(), v.end());
                    map[i][j].first = v.rbegin()->first+1;
                    map[i][j].second = v.rbegin()->first;
                }
            }
        }
    }
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
