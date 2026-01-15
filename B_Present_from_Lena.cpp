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




void solve()
{
    int n;
    cin >> n;
    int sz = 2 * n + 1;
    vector<vector<int>> ans(sz, vector<int>(sz, -1));

    for (int i = 0; i <= n; i++) 
    {
        int start = n - i, end = n + i;
        int val = 0;
        for (int j = start; j <= end; j++) 
        {
            ans[i][j] = val;
            ans[sz - i - 1][j] = val;
            if (j < n)
                val++;
            else
                val--;
        }
    }

    for (int i = 0; i < sz; i++) 
    {
        int last = -1;
        for (int j = sz - 1; j >= 0; j--) 
        {
            if (ans[i][j] != -1) 
            {
                last = j;
                break;
            }
        }
        for (int j = 0; j <= last; j++) 
        {
            if (ans[i][j] == -1)
                cout << "  ";
            else
                cout << ans[i][j] << (j == last ? "" : " ");
        }
        cout << endl;
    }
}

signed main()
{
    fast

        ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
