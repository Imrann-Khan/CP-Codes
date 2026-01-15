#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pi 3.141592653589793238462643383279502884197
using namespace std;

const ll MOD = 1e9 + 7;
const int N = 1e7 + 1;
vector<bool> prime(N);
vector<int> pr;

void permute(string &s, int i, vector<string> &ans, int k)
{
    if (ans.size() == k + 5)
        return;
    if (i == s.size())
    {
        ans.push_back(s);
        return;
    }
    rep(j, i, s.length() - 1)
    {
        swap(s[i], s[j]);
        permute(s, i + 1, ans, k);
        swap(s[i], s[j]);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s = str.substr(0, n);
    vector<string> ans;
    permute(s, 0, ans, k);
    sort(ans.begin(), ans.end());
    int r = min(k - 1, (int)ans.size() - 1);
    rep(i, 0, r) cout << ans[i] << endl;
}

signed main()
{
    fast

        ll t;
    cin >> t;
    int cnt = 1;
    while (t--)
    {
        cout << "Case " << cnt++ << ":\n";
        solve();
    }
}
