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

int n;
vector<string> ans;

void generate_paranthesis(int open, int close, string s)
{
    if (open == n and close == n)
    {
        ans.push_back(s);
        return;
    }

    // if open bracket count is less than n
    if (open < n)
    {
        generate_paranthesis(open + 1, close, s + "(");
    }

    // if close bracket is less than close bracket
    if (open > close)
    {

        generate_paranthesis(open, close + 1, s + ")");
    }
}

void solve()
{
    cin >> n;
    generate_paranthesis(0, 0, "");
    for (auto str : ans)
    {
        cout << str << endl;
    }
}

signed main()
{
    fast
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
