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

static const ll MOD = 1000000007LL;

ll get_hash(int l, int r, vector<ll>& p, vector<ll>& hash)
{
    ll h = (hash[r+1] - (p[r-l+1] * hash[l]) % MOD );
    return h<0?h+MOD:h;
}

void solve()
{
    string s;
    cin >> s;
    int prime = 7;
    vector<ll> p(s.size()+1);
    vector<ll> hash(s.size()+1);
    p[0] = 1;
    hash[0] = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        p[i] = (p[i-1] * prime) % MOD;
        hash[i] = (hash[i-1]*prime + (s[i-1] - 'a' + 1)) % MOD;
    }

    for (int i = 0; i < s.size(); i++)
    {  
       bool f = true;
       int j=0;
        while(j<s.size())
        {
            int len = min(i+1, (int)s.size()-j);
            if(get_hash(0,len-1, p, hash)!=get_hash(j,j+len-1, p, hash))
            {
                f=0;
                break;
            }
            j+=len;
        }
        if(f) cout<<i+1<<" ";
    }
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
