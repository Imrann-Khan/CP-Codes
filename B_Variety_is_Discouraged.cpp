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
    vector<int> a(n);
    ll freq[n + 1] = {0};
    rep(i, 0, n - 1)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    set<int> s;
    rep(i, 0, n)
    {
        if (freq[i] == 1)
            s.insert(i);
    }
    int mx = 0, left = -1, right = -1;
    int i = 0, j = 0;
    while (j < n)
    {
        if (s.find(a[j]) == s.end())
        {
            i = j + 1;
        }
        else
        {
            int length = j - i + 1;
            if (length > mx)
            {
                mx = length;
                left = i;
                right = j;
            }
        }
        j++;
    }
    if (mx == 0)
        cout << "0\n";
    else
        cout << left + 1 << " " << right + 1 << "\n";
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
