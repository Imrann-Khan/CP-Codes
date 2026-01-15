#include <iostream>
#include <vector>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
using namespace std;

string AddGap(int n)
{
    string s = "";
    rep(i, 1, n)
    {
        s += " ";
    }
    return s;
}

vector<string> Print(int n)
{
    if (n == 1)
    {
        vector<string> ans;
        ans.push_back("X");
        return ans;
    }
    vector<string> s = Print(n - 1);
    int h = s.size();
    int w = s[0].size();
    vector<string> res;
    res.reserve(3 * h);
    rep(i, 0, h - 1)
    {
        string tmp = s[i];
        tmp += AddGap(w);
        tmp += s[i];
        res.push_back(tmp);
    }

    rep(i, 0, h - 1)
    {
        string tmp = AddGap(w);
        tmp += s[i];
        tmp += AddGap(w);
        res.push_back(tmp);
    }

    rep(i, 0, h - 1)
    {
        string tmp = s[i];
        tmp += AddGap(w);
        tmp += s[i];
        res.push_back(tmp);
    }

    return res;
}

void solve(int n)
{
    vector<string> ans = Print(n);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    cout << "-\n";
}

signed main()
{
    int n;
    while (cin >> n)
    {
        if (n != -1)
            solve(n);
        else
            break;
    }
    return 0;
}
