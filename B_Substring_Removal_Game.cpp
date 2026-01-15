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
    string s;
    cin>>s;
    vector<int> ans;
    int tmp=0;
    if(s[0]=='1') tmp=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='0' and tmp>0)
        {
            ans.push_back(tmp);
            tmp=0;
        }
        else if(s[i]=='1')
        {
            tmp++;
        }
    }
    if(tmp>0) ans.push_back(tmp);
    sort(ans.begin(),ans.end(),greater<int>());
    int res=0;
    for(int i=0;i<ans.size();i+=2)
    {
        res+=ans[i];
    }
    cout<<res<<endl;
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
