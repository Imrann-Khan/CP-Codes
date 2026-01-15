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


int match(string s, string t)
{
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i]) cnt++;
    }
    return cnt; 
}


void solve()
{
    int n1,n2;
    cin>>n1>>n2;

    string s,t;
    cin>>s>>t;

    set<string> comb;

    for(int i=0;i<n2;i++)
    {
        string s="";
        for(int j=i;j<n2;j++)
        {
            s+=t[j];
            comb.insert(s);
        }
    }

    string tmp;
    int mn=1001;
    for(auto i:comb)
    {
        if(s.size()!=i.size()) continue;
        if(match(s,i)<mn)
        {
            mn=match(s,i);
            tmp=i;
        }
    }

    vector<int> ans;
    for(int i=0;i<n1;i++)
    {
        if(s[i]!=tmp[i])
        {
            ans.push_back(i);
        }
    }
    cout<<mn<<endl;

    for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" ";
    cout<<endl;
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
