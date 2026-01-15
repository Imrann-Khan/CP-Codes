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
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, char>> v(26, {0, 'a'});
    for (int i = 0; i < 26; i++)
        v[i] = {0, 'a' + i};
    for (int i = 0; i < n; i++)
    {
        v[s[i] - 'a'].first++;
    }
    // sort(v.begin(), v.end(), greater<pair<int, char>>());
    sort(v.begin(), v.end(), greater<pair<int, char>>());
    while (v[0].first > 1)
    {
        cout << v[0].second;
        v[0].first--;
        sort(v.begin(), v.end(), greater<pair<int, char>>());
    }
    for (int i = 0; i < 26; i++)
    {
        if (v[i].first)
            cout << v[i].second;
    }
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