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
    string s;
    cin >> n >> s;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    int ans = n;
    if (n & 1)
    {
        pair<int, char> ev[n][26];
        pair<int, char> tev[26];
        pair<int, char> odd[n][26];
        pair<int, char> todd[26];
        for (int i = 0; i < 26; i++)
        {
            odd[0][i].second = char(i + 'a');
            odd[0][i].first = 0;
            ev[0][i].second = char(i + 'a');
            ev[0][i].first = 0;
        }
        odd[0][s[0] - 'a'].second = s[0];
        odd[0][s[0] - 'a'].first++;
        for (int k = 1; k < n; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                odd[k][i].second = char(i + 'a');
                odd[k][i].first = 0;
                ev[k][i].second = char(i + 'a');
                ev[k][i].first = 0;
            }
            if (k & 1)
            {
                for (int i = 0; i < 26; i++)
                {
                    odd[k][i].second = odd[k - 1][i].second;
                    odd[k][i].first = odd[k - 1][i].first;
                }
                odd[s[k] - 'a']->first++;
            }
            else
            {
                for (int i = 0; i < 26; i++)
                {
                    ev[k][i].second = odd[k - 1][i].second;
                    ev[k][i].first = odd[k - 1][i].first;
                }
                ev[s[k] - 'a']->first++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                todd[s[0] - 'a'].second = s[i];
                todd[s[0] - 'a'].first++;
            }
            else
            {
                tev[s[0] - 'a'].second = s[i];
                tev[s[0] - 'a'].first++;
            }
        }
        for (int k = 0; k < n; k++)
        {
            pair<int, char> nev[26];
            pair<int, char> nodd[26];
            if (k & 1)
            {
                for (int i = 0; i < 26; i++)
                {
                    nodd[i].second = odd[k - 1][i].second;
                    nodd[i].first = odd[k - 1][i].first;
                }
                for (int i = 0; i < 26; i++)
                {
                    nodd[i].second = tev[i].second;
                    nodd[i].first += tev[i].first - ev[k][i].first;
                }
                nev[s[k] - 'a'].first--;
            }
            else
            {
                if (k == 0)
                {
                    for (int i = 0; i < 26; i++)
                    {
                        nev[i].second += todd[i].second;
                        nev[i].first += todd[i].first;
                    }
                }
                else
                {
                    for (int i = 0; i < 26; i++)
                    {
                        nev[i].second = ev[k - 1][i].second;
                        nev[i].first = ev[k - 1][i].first;
                    }
                    for (int i = 0; i < 26; i++)
                    {
                        nev[i].second = todd[i].second;
                        nev[i].first += todd[i].first - odd[k][i].first;
                    }
                }
                nev[s[k] - 'a'].first--;
            }
            sort(nev, nev + 26, greater<pair<int, char>>());
            sort(nodd, nodd + 26, greater<pair<int, char>>());
            int temp = n - nev[0].first - nodd[0].first;
            if (nev[0].first > n / 2 or nodd[0].first > n / 2)
                ans++;
            ans = min(ans, temp);
        }
    }
    else
    {
        pair<int, char> ev[26];
        pair<int, char> odd[26];
        for (int i = 0; i < 26; i++)
        {
            ev[i].second = char(i + 'a');
            ev[i].first = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                odd[s[i] - 'a'].second = s[i];
                odd[s[i] - 'a'].first++;
            }
            else
            {
                ev[s[i] - 'a'].second = s[i];
                ev[s[i] - 'a'].first++;
            }
        }
        sort(ev, ev + 26, greater<pair<int, char>>());
        sort(odd, odd + 26, greater<pair<int, char>>());
        ans = n - ev[0].first - odd[0].first;
        if (ev[0].first > n / 2 or odd[0].first > n / 2)
            ans++;
        cout << ans << endl;
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