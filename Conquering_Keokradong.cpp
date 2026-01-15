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
    int n, k;
    cin >> n >> k;
    vector<int> dis(n + 2, 0);
    rep(i, 1, n + 1)
    {
        cin >> dis[i];
        dis[i] += dis[i - 1];
    }
    // rep(i, 1, n + 1)
    // {
    //     cout << dis[i] << " ";
    // }
    // cout << endl;
    int tmp = 0;
    int lst = 0;
    int p = n;
    k++;
    vector<int> ans;
    // cout << dis[n + 1] << endl;
    while (k != 0)
    {
        tmp = lst + (dis[n + 1] - lst) / k;
        int avg = (dis[n + 1] - lst) / k;
        // cout << tmp << " ";
        int x = lower_bound(dis.begin(), dis.end(), tmp) - dis.begin();
        cout << avg << " " << dis[x] << endl;
        // if (abs(dis[x - 1] - tmp) < abs(dis[x] - tmp))
        // {
        //     ans.push_back(dis[x - 1] - lst);
        //     lst = dis[x - 1];
        //     // cout << dis[x - 1] << " ";
        // }
        // else
        // {
        //     ans.push_back(dis[x] - lst);
        //     lst = dis[x];
        //     // cout << dis[x] << " ";
        // }
        if (dis[x] > tmp)
        {
            ans.push_back(dis[x - 1] - lst);
            lst = dis[x - 1];
        }
        else
        {
            ans.push_back(dis[x] - lst);
            lst = dis[x];
        }
        k--;
        p--;
        // cout << lst << endl;
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
    for (auto i : ans)
        cout << i << endl;
}

signed main()
{
    fast
        ll t;
    cin >> t;
    int p = 1;
    while (t--)
    {
        cout << "Case " << p++ << ": ";
        solve();
    }
}
