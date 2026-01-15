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

const int mod = 1e9+7;

void fillLps(string &s, vector<int> &lps)
{
    int n = s.size();
    int i=1;
    lps[0]=0;
    int len=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0) lps[i]=0,i++;
            else len=lps[len-1];
        }
    }
}

void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    vector<int> lps(n);
    fillLps(s,lps);
    for(auto i:lps) cout<<i<<" ";
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